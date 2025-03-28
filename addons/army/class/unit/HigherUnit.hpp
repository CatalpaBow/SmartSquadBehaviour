GCLASS(HigherUnit) =  [
	["#base", GCLASS(UnitBase)],
	["#create",{
		params["_unitName","_side","_location","_mission","_lowerUnits"];
		_self set ["lowerUnits",_lowerUnits];
	}],
	["#type","Higher"],
	["lowerUnits",[]],
	["AssignMission",{
		params["_mission"];
		_self set ["mission",_mission];
		_lowerUnits = _self get "lowerUnits";
		_subMissionList = _mission call ["CreateSubMission"];
		{
			LOG("OrderMissionHighToLow");
			_x params["_unit"]; 
			private _missionNum = _forEachIndex % count _subMissionList; 
			private _subMission = _subMissionList select _missionNum; 
			_unit call ["AssignMission",[_subMission]];
		}forEach(_lowerUnits);
	}],
	["InitialDeploy",{
		params["_initialDeploymentArea"];
		_self set ["deploymentArea",_initialDeploymentArea];
		_subAreaList = _initialDeploymentArea call ["FindFebaInside",_self get "side"];
		_msg = format["(higherUnit InitialiDeplyoment)StartLoop"];
		LOG(_msg);
		{
			_x params["_unit"];
			private _febaIndex = _forEachIndex % (count _subAreaList);
			private _feba = _subAreaList select _febaIndex;
			_msg = format["(higherUnit InitialiDeplyoment)LoopInfo:febaCount:%1",_febaIndex];
			LOG(_msg);
			_unit call ["InitialDeploy",_feba];
		}forEach(_self get "lowerUnits");
	}],
	["Instantiate",{		
		{_x call ["Instantiate"]}forEach(_self get "lowerUnits");
	}],
	["SubUnitCount",{
		count (_self get "lowerUnits");
	}]
	
];