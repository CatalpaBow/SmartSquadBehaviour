GCLASS(LowestUnit) = [
	["#base", GCLASS(UnitBase)],
	["#type","Lowest"],
	["#create",{
		params["_unitName","_side","_deploymentArea","_mission","_group","_unitClassNameList","_isInstanced"];
		_self set ["group",_group];
		_self set ["unitClassNameList",_unitClassNameList];
		_self set ["isInstanced",_isInstanced];
	}],
	["#delete",{
		private _grp = _self get "group";
		if(isNil "_grp")exitWith{};
		{deleteVehicle _x}forEach(units _grp);
		deleteGroup _grp;
		LOG("Unit deleted");
	}],
	["group",grpNull],
	["unitClassNameList",[]],
	["isInstanced",false],
	["AssignMission",{
		params["_mission"];
		_self set ["mission",_mission];
		_grp = _self get "group";
		_mission call ["AssignTaskToGroup",[_grp]];
		_msg = format["Unit(%1) assigned new mission.MissionType:%2",_self get "unitName",_mission get "type"];
		LOG(_msg);
	}],
	["Instantiate",{		
		//If unit is not deployed,nothing to do.
		_deploymentArea = _self get "deploymentArea";
		if(isNil "_deploymentArea")exitWith{
			LOG("Unit has not deployed and will not spawned.");
			false;
		};
		_grp = _self call ["SpawnGroup"];
		_self set ["group",_grp];
		_self get "mission" call ["AssignTaskToGroup",_grp];
		LOG("Unit(%1)'s group(%2) assgined mission task.");
		true;
		
	}],
	["Uninstantiate",{
		_grp = (_self get "group");
		_grpID = groupId _grp;
		if!(isNil "_grp")exitWith{
		};
		deleteGroup _grp;
		_msg = format["Unit(%1) is now uninstantiated.Unit(%1)'s group(%2) has benn deleated.",_self get "unitName",_grpID];
		LOG(_msg);
	}],
	["SpawnGroup",{
		_deploymentArea = _self get "deploymentArea";
		_side = west;
		if(_self get "side" == "west")then{
			_side = west;	
		} else{
			_side = east;
		};
		_grp = createGroup _side;
		_grpID = groupId _grp;
		_spawnPos = _deploymentArea call ["GetPosition"];	
		{ _grp createUnit[_x,_spawnPos,[],0,"NONE"]} forEach (_self get "unitClassNameList");
		_msg = format["Group(%1) of unit(%2) spawned.",_grpID,_self get "unitName"];
		LOG(_msg);
		_grp;
	}],
	["InitialDeploy",{
		params["_initialDeploymentArea"];
		_self set ["deploymentArea",_initialDeploymentArea];
	}],
	["SubUnitCount",{
		count (_self get "unitClassNameList");
	}]
];