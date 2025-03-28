GCLASS(BattlePositionList) = [
    ["idCounter",-1],
    ["dic",nil],
	["#create", {
        _self set ["dic",createHashMap];
	}],
    ["IssueID",{
        _self get "idCounter" + 1;
    }],
    ["CreateByModule",{
        params["_module"];
        _pos = getPos _module;
        _area = createHashMapObject [GCLASS(AreaInfo),[_pos]];
        _priority = _module getVariable "priority";
        _ownerSide = _module getVariable "ownerSide";
        _self call ["Create",[_area,_priority,_ownerSide]];
    }],
    ["Create",{
        params["_area","_priority","_ownerSide"];
        private _id = _self call "IssueID";
        //Create bp
        _bp = createHashMapObject[GCLASS(BattlePosition),[_area,_priority,_id,_ownerSide]];
        _self get "dic" set [_id,_bp];
        _bp;
    }],
    ["GetBP",{
    }]
];