GCLASS(Army) = [
	/* Variables */
	["side", ""],
	["initialManPower",0],
	["manPower",0],
	["armyOrganization",[]],
	["unit",nil],	
	/* Constructer */ 
	["#create", {	
		params ["_side","_initialManPower","_armyOrganization"];
		_self set ["side",_side];
		_self set ["initialManPower",_initialManPower];
		_self set ["armyOrganization",_armyOrganization];
		_self set ["manPower",_initialManPower];
		_self set ["unit",nil];
	}],
	/* Methods */
	["ConvertManPowerToUnit",{
		private _squadSize =  count (_self get "armyOrganization" get "infSquadUnitNames");
		private _numberOfSquads = round ((_self get "initialManPower") / _squadSize);
		private _platoonLowerUnit = [];
		
		//Squad initial statement
		private _side = _self get "side";		
		private _location = "";
		private _mission = createHashMapObject[GCLASS(NoneMission)];
		private _group = grpNull;
		private _infClassNames = _self get "armyOrganization" get "infSquadUnitNames";
		private _isInstanced = false;

		//Create infantry squads and add them to the platoon as subunits.
		for "_i" from 1 to _numberOfSquads  do { 
			private _squadName = format ["Inf1-%1",_i];
			private _infSquad = createHashMapObject [GCLASS(LowestUnit),[_squadName,_side,_location,_mission,_group,_infClassNames,_isInstanced]];
			_platoonLowerUnit pushBack _infSquad;
		};

		//Create an infantry platoon and add it to the army as an owned unit.
		private _unitName = "InfPlt1-1";
		private _location = "";
		private _mission = createHashMapObject[GCLASS(NoneMission)];
		private _higherUnit = createHashMapObject [GCLASS(HigherUnit),[_unitName,_side,_location,_mission,_platoonLowerUnit]];
		
		private _rootUnit = createHashMapObject [GCLASS(HigherUnit),["RootUnit",_side,_location,_mission,[_higherUnit]]];
		//Create an west army unit.
		_self set ["unit",_rootUnit];
	}],
	["InitialDeploy",{
		params["_initialDeploymentArea"];
		//After converting manpower into units, execute the initial deployment of owned units.
		//The initial deployment area is the army-side FEBA, get from the battlefield instance."
		_self call ["ConvertManPowerToUnit"];
		_self call ["DeployUnitToFEBA",[_initialDeploymentArea,_self get "unit"]];
	}],
	["DeployUnitToFEBA",{
		params["_area","_unit"];
		private _id = _area get "id";
		private _name = _area get "name";
		private _position = _area call ["GetPosition"];
		private _areaInfo = createHashMapObject[EGCLASS(battleField,AreaInfo),[_id,_name,_position]];
		_unit set ["deploymentArea",_areaInfo];
		if("Lowest" in (_unit get "#type"))exitWith{};
		//_msg = format["(higherUnit InitialiDeplyoment)StartLoop"];
		//LOG(_msg);

		private _subAreaList = _area call ["FindFebaInside",_self get "side"];
		{
			_x params["_subUnit"];
			//LOG("InitialDeployLoopCalled");
			private _subAreaIndex = _forEachIndex % (count _subAreaList);
			private _subArea = _subAreaList select _subAreaIndex;
			//_msg = format["(higherUnit InitialiDeplyoment)LoopInfo:febaCount:%1",_subAreaIndex];
			//LOG(_msg);
			_self call ["DeployUnitToFEBA",[_subArea,_subUnit]];
		}forEach(_unit get "subUnits");
	}],
	["OrderInitialMission",{
		params["_missionArea"];
		//NOTE:At this stage, all units are ordered on defense missions for now.
		private _unit = _self get "unit";
		private _missionAreaInfo = _missionArea call ["CreateAreaInfo"];
		private _mission = createHashMapObject[GCLASS(DefenseMission),[_missionAreaInfo,_self get "side"]];

		_self call ["OrderMission",[_mission,_unit,_missionArea]];
		//_unit call ["AssignMission",[_mission]];
	}],
	["OrderMission",{
		params["_mission","_unit","_missionArea"];
		_unit set ["mission",_mission];
		if("Lowest" in (_unit get "#type"))exitWith{};

		private _febaList = _missionArea call ["FindFebaInside",[_self get "side"]];
		private _areaInfoList = _febaList apply { _x call ["CreateAreaInfo"];};
        private _subMissionList = _areaInfoList apply { createHashMapObject[GCLASS(DefenseMission),[_x,_self get "side"]]};
		{
			_x params["_subUnit"];
			private _missionIndex = _forEachIndex % (count _subMissionList);
			private _subMission = _subMissionList select _missionIndex;
			private _subArea = _febaList select _missionIndex;
			_self call ["OrderMission",[_subMission,_subUnit,_subArea]];
		}forEach(_unit get "subUnits");
	}],
	["InstantiateAllUnits",{
		//NOTE:Temporary implementation
		_self get "unit" call ["Instantiate",[]];
	}]
];