GCLASS(DebugDisplay) = [
	/* Variables */
	["armyList",nil],
    ["unitTreeCtl",nil],
	["unitInfoCtl",nil],
	/* Constructer */ 
	["#create", {	
		params["_armyList"];
		_self set ["armyList",_armyList];
	}],
	["Open",{
        private _armyList = _self get "armyList";
        //CreateDisplay
        private _dis = findDisplay 313 createDisplay "SSBDisplayTest";
        private _unitTreeCtl = (_dis displayCtrl 1100) controlsGroupCtrl 1105;
        private _unitInfoCtl = (_dis displayCtrl 1200) controlsGroupCtrl 1201;
        _self set ["unitTreeCtl",_unitTreeCtl];
        _self set ["unitInfoCtl",_unitInfoCtl];

        _unitTreeCtl tvAdd[[],"West"];
        _unitTreeCtl tvAdd[[],"East"];
        private _westIndex = _armyList findIf {_x get "side" == "west"};
        private _eastIndex = _armyList findIf {_x get "side" == "east"};
        if(_westIndex != -1)then{
            [_unitTreeCtl,[0],_armyList select _westIndex get "lowerUnits"]call FUNC(recursion);
        };
        if(_eastIndex != -1)then{
            [_unitTreeCtl,[1],_armyList select _eastIndex get "lowerUnits"]call FUNC(recursion);
        };
        _unitTreeCtl setVariable["treeSelChangedHdlr",_self];
        _unitTreeCtl ctrlAddEventHandler ["TreeSelChanged",{
	        params ["_control", "_selectionPath"];
            _control getVariable "treeSelChangedHdlr" call ["HandleTreeSelChanged",[_control,_selectionPath]];
        }];
	}],
	["HandleTreeSelChanged",{
        params ["_control", "_selectionPath"];

        private _sideIndex = _selectionPath select 0;
        private _side =  _self get "armyList" select _sideIndex;
        private _unitInstancePath = [];
        private _unitParent = _side;
        _selectionPath deleteAt 0;
        _msg = format["selectionPath:%1",_selectionPath];
        LOG(_msg);
        {
            _msg = format["pathPart:%1,brothersCount:%2",_x,( count (_unitParent get "lowerUnits"))];
            LOG(_msg);
            _unitInstancePath pushBack (_unitParent get "lowerUnits" select _x);
            _unitParent = _unitParent get "lowerUnits" select _x;
        }forEach(_selectionPath);
        private _count = count _unitInstancePath;
        private _unitParent = _side;
        if( (count _unitInstancePath) != 0)then{
            _unitParent = _unitInstancePath select (count _unitInstancePath - 2);
        };
        private _unitNamePath = _unitInstancePath apply {_x get "unitName"};
        LOG(_unitNamePath);

        private _unitInfoCtl = _self get "unitInfoCtl";
        lnbClear _unitInfoCtl;
        _unitInfoList = (_unitParent get "lowerUnits")apply{
            private _name = _x get "unitName";
            private _mission = _x get "mission" get "type";
            private _deploymentArea = "kari";
            private _subUnitCount = str (_x call ["SubUnitCount"]);
            [_name,_mission,_deploymentArea,_subUnitCount];
        };
        { _unitInfoCtl lnbAddRow  _x;}forEach(_unitInfoList);
	}]

];