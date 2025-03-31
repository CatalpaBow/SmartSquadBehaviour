GCLASS(BattlePosition) = [
    ["#base",GCLASS(IBattleArea)],
	["priority",-1],
    ["ownerSide",""],
    ["connectedBPLows",[]],
    ["connectedBPSames",[]],
    ["connectedBPHighs",[]],
	["#create", {	
		params ["_id","_name","_position","_priority","_ownerSide"];
        _self set ["id",_id];
        _self set ["name",_name];
        _self set ["position",_position];
		_self set ["priority",_priority];
        _self set ["ownerSide",_ownerSide];
	}],
    ["FindFebaInside",{
        params["_side"];
        [_self];
    }],
    ["SetBPConection",{
        params["_lowList","_sameList","_highList"];
        _self set ["connectedBPLows",_lowList];
        _self set ["connectedBPSames",_sameList];
        _self set ["connectedBPHighs",_highList];
    }],
    ["GetPosition",{
        _self get "position";
    }],
    ["GetLinkedBPs",{
        (_self get "connectedBPLows") + (_self get "connectedBPSames") + (_self get "connectedBPHighs");
    }]
];