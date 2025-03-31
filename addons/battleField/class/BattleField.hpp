GCLASS(BattleField) = [
    ["#base",GCLASS(IBattleArea)],
    ["areaIdIssuer",nil],
	["battleZones",nil],
    ["#str",{"BattleField"}],
	["#create", {	
        params["_pos"];
        private _idIssuer = createHashMapObject[GCLASS(IDIssuer)];
        _self set ["id",_idIssuer call ["Issue"]];
        _self set ["name","BattleField"];
        _self set ["position",_pos];
        _self set ["areaIdIssuer",_idIssuer];
        _self set ["battleZones",[]];
	}],
    ["FindFebaInside", {
        params["_side"];
        if(count (_self get "battleZones") <= 0)exitWith{
            LOG("(BattleField)The count of battleZones is zero.FEBA not found.");
            nil;
        };
        private _baList = _self get "battleZones";
        private _ba = _baList select 0;
        [_ba];
    }],
    ["GetPosition",{
        _self get "position";
    }],
    ["NewBattleZone",{
        params["_battleZoneCreater"];
        _ba = _battleZoneCreater call ["Create",[_self get "areaIdIssuer"]];
        _self get "battleZones" pushBack _ba;
    }]
];