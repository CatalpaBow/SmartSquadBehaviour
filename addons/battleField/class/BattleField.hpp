GCLASS(BattleField) = [
    ["#base",GCLASS(IBattleArea)],
    ["areaInfo",nil],
	["battleZones",[]],
    ["#str",{"BattleField"}],
	["#create", {	
		params ["_areaInfo","_battleZoneList"];
        _self set ["areaInfo",_areaInfo];
        _self set ["battleZones",_battleZoneList];
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
        _self get "areaInfo" get "position";
    }]
];
