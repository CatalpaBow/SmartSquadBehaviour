GCLASS(NoneMission) = [
    ["#base",GCLASS(MissionBase)],
	["#create",{}],
    ["CreateSubMission",{
        [_self];
    }],
    ["type","none"],
    ["AssignTaskToGroup",{
        params["_group"];
        //Do nothing
    }]
];
