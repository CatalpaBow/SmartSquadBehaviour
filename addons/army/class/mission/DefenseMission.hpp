GCLASS(DefenseMission)  = [
    ["#base",GCLASS(MissionBase)],
	["#create",{
		params["_area","_side"];
		_self set ["area",_area]; //IBattleArea
		_self set ["side",_side]; //String
	}],
    ["type","defense"],
    ["area",nil],
    ["side",""],
    ["CreateSubMission",{
        private _missionArea = _self get "area";
		private _sideSelf = _self get "side";
        _msg = format["(DefenseMission)SideSelf:%1",_sideSelf];
        LOG(_msg);
		private _febaList = _missionArea call ["FindFebaInside",[_sideSelf]];
        private _subMissionList = _febaList apply { createHashMapObject[GCLASS(DefenseMission),[_x,_sideSelf]]};
        _subMissionList;
    }],
    ["AssignTaskToGroup",{
        params["_group"];
        //Do nothing when no group.
        if(isNull _group)exitWith{};

		//Give waypoints to in game group to perform mission.
		_areaPos = _self get "area" get "position";
        _wp = _group addWaypoint[_areaPos,0];
        _wp setWaypointType "HOLD";
        _wp setWaypointBehaviour "AWARE";
        _wp setWaypointCombatMode "YELLOW";
    }]
];
