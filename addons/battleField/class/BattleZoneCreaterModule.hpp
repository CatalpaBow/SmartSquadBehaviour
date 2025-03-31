GCLASS(BattleZoneCreaterModule) = [
    ["module",nil],
	["#create", {
	}],
    ["Create",{
        params["_idIssuer"];
        private _module = _self get "module";
        private _id =  _idIssuer call ["Issue"];
        private _name = _module getVariable["name",""];
        if(_name == "")then{
            _name = format["BattleZone %1",_id];
        };
        private _position = getPos _module;
        private _baPriority = _module getVariable "priority";
        private _baOwnerSide = _module getVariable "ownerSide";

        //CreateBattlePositions
        private _battlePositionCreater = createHashMapObject[GCLASS(BattlePositionCreaterModule),[_idIssuer]];
        private _linkedBPModuleList = [_module,QGVAR(battlePosition)] call EFUNC(common,treeSearch);
        private _battlePositionList = _linkedBPModuleList apply {_battlePositionCreater call ["Create",[_x]]};
        //Set BattlePosition Connection
        {_x setVariable ["BPClassInstance",_battlePositionList select _forEachIndex]}forEach(_linkedBPModuleList); //Hack: Tying class to module for sort process.

        {
            _x params["_bpModule"];
            _syncedBPs = [_bpModule,QGVAR(battlePosition)] call EFUNC(common,getSyncedModules);
            _refPriority = _bpModule getVariable "priority";
            _sortedList = [_syncedBPs,_refPriority] call FUNC(lowHighPrioritySort);//Hack: Use BPClassInstance variable in sort process.
            (_battlePositionList select _forEachIndex) call ["SetBPConection",_sortedList]; 
        }forEach(_linkedBPModuleList);


        
        //{_x setVariable ["BPClassInstance",nil] }forEach(_linkedBPModuleList);//Hack: Clear tying.
        createHashMapObject[GCLASS(BattleZone),[_id,_name,_position,_battlePositionList,_baPriority,_baOwnerSide]];
    }],
    ["SetModule",{
        params["_module"];
        _self set ["module",_module];
    }]
];