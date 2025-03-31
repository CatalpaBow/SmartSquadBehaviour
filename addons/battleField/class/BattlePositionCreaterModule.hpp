GCLASS(BattlePositionCreaterModule) = [
    ["idIssuer",nil],
	["#create", {
        params["_idIssuer"];
        _self set ["idIssuer",_idIssuer];
	}],
    ["Create",{
        params["_module"];
        private _id = _self get "idIssuer" call ["Issue"];
        private _name = _module getVariable ["name",""];
        if(_name == "")then{
            _name = format["BattlePosition %1",_id];
        };
        private _pos = getPos _module;
        private _area = createHashMapObject [GCLASS(AreaInfo),[_id,_name,_pos]];
        private _priority = _module getVariable "priority";
        private _ownerSide = _module getVariable "ownerSide";


        createHashMapObject[GCLASS(BattlePosition),[_id,_name,_pos,_priority,_ownerSide]];
    }]
];