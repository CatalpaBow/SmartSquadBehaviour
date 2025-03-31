GCLASS(BattleZone) = [
    ["#base",GCLASS(IBattleArea)],
	["battlePositions",[]],
	["priority",0],
    ["ownerSide","none"],
	["#create", {	
		params ["_id","_name","_position","_battlePositions","_priority","_ownerSide"];
        _self set ["id",_id];
        _self set ["name",_name];
        _self set ["position",_position];
        _self set ["battlePositions",_battlePositions];
		_self set ["priority",_priority];
        _self set ["ownerSide",_ownerSide];
	}],
    ["FindFebaInside",{
        params["_side"];
        _self call ["FindFebaRefactor",[_side]];
        //TODO:ゾーンに接続されたBattlePositionチェーンから始点となるバトルポジションをそれぞれ選択するが、現在の実装だとすべてのBattlePositionチェーンの中から最小、最大となるバトルポジションを選択するようになっている。
        //つまり、最小、最大値が互いに異なるBattlePositionチェーンがある場合は、どちらか一つしか選択されない。
        //誤:全てBattlePositionの中から最小もしくは最大となるバトルポジションを一つ選ぶ。
        //正:BattlePositionチェーンリストの中から最少もしくは最大の始点となるバトルポジションをそれぞれ一つずつ選ぶ。
        //BPチェーン:このように同期されたBPモジュールのこと→ BP-BP-BP
        /*
        private _bpAll = _self get "battlePositions";
        private _bpPriorityAll =  _bpAll apply {_x get "priority"};
        private _westIsMinEastIsMax_priority = -1;
        if(_side == "west") then{ 
            _westIsMinEastIsMax_priority = selectMin _bpPriorityAll;
        }else{
            _westIsMinEastIsMax_priority = selectMax _bpPriorityAll;
        };
        private _startingNodesOfFebaSearch = _bpAll select {_x get "priority" == _westIsMinEastIsMax_priority};
        private _searchResult = _startingNodesOfFebaSearch apply { _self call ["FindFebaSignlyLink",[_x,_side]] };
        private _foundFebaList = [];
        {_foundFebaList append _x }forEach(_searchResult); //Flatten
        _foundFebaList;
        */
    }],
    ["FindFebaSignlyLink",{
        params["_bp","_side"];
        //FIXME:If circular linked,it caused infinity loop!. Need circular detect.
        LOG("-FindFebaSignlyLink-");
        _msg = format["SideInfo Arg:%1,Self:%2",_side,_bp get "ownerSide"];
        LOG(_msg);
        private _nextIDs = -1;

        //West:low to high. East:high to low.
        if(_bp get "ownerSide" == "west")then{
            LOG("Low to high search.WestSide");
            _nextIDs = _bp get "connectedBPHighs";
        } else {
            LOG("High to low search.OtherSide");
            _nextIDs = _bp get "connectedBPLows";
        };

        //If there is no next connection, it is considered terminated.
        if(count _nextIDs <= 0)exitWith{
            LOG("Reached to terminated of link.There is no feba boundry.The terminated node is feba instead.");
            [_bp];
        };
        
        //Consider the boundary where the area owner switches as the FEBA, and return the FEBA on the Side specified by the argument.
        //TODO:Support for multiple NextIDs
        private _nextID = _nextIDs select 0;
        private _nextBPIndex = (_self get "battlePositions") findIf {_x get "id" == _nextID}; 
        private _nextBP = _self get "battlePositions" select _nextBPIndex; 
        _isFound = !(isNil "_nextBP");
        _msg = format["NextID is %1.Is found nextBP?:%2 ",_nextID,_isFound];
        LOG(_msg);
        private _ownerSelf = _bp get "ownerSide";
        private _ownerNext = _nextBP get "ownerSide";
        if(_ownerSelf != _ownerNext)exitWith{
            LOG("FEBA Boundry found.");
            _msg = format["<BoundrySideInfo> Self is %1,Next is %2",_ownerSelf,_ownerNext];
            LOG(_msg);
            private _feba = nil;
            if(_ownerSelf == _side)then{
                _msg = format["Feba is self.ID is %1",_bp get "id"];
                LOG(_msg);
                _feba = _bp;
            }else{
                _msg = format["Feba is next.ID is %1",_bp get "id"];
                LOG(_msg);
                _feba = _nextBP;
            };
            [_feba];
        };
        LOG("FEBA boundry has not been found.Search next link");
        //If the area owner has not switched, consider that the FEBA has not been found yet and continue searching the next area.
        _self call ["FindFebaSignlyLink",[_nextBP,_side]];
    }],
    ["GetPosition",{
        _self get "position";
    }],
    ["FindFebaRefactor",{
        params["_side"];
        private _bpAll = _self get "battlePositions";
        private _sideOwnedBPs = _bpAll select {_x get "ownerSide" == _side};
        private _foundFeba = _sideOwnedBPs select { 
            private _linkedBPIDs = _x call ["GetLinkedBPs"];
            private _linkdeBPInstances = _linkedBPIDs apply {
                _x params["_ID"];
                private _bpList = (_self get "battlePositions") ;
                private _foundBPIndex = _bpList findIf { _x get "id" == _ID};
                _bpList select _foundBPIndex;
            };
            (_linkdeBPInstances findIf {_x get "ownerSide" != _side}) > -1; 
        };
        _foundFeba;
    }]
];