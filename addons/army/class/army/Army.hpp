GCLASS(Army) = [
	/* Variables */
	["side", ""],
	["initialManPower",0],
	["manPower",0],
	["armyOrganization",[]],
	["lowerUnits", []],	
	/* Constructer */ 
	["#create", {	
		params ["_side","_initialManPower","_armyOrganization"];
		_self set ["side",_side];
		_self set ["initialManPower",_initialManPower];
		_self set ["armyOrganization",_armyOrganization];
		_self set ["manPower",_initialManPower];
		_self set ["lowerUnits",[]];
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

		_self get "lowerUnits" pushBack _higherUnit;
	}],
	["InitialDeploy",{
		//After converting manpower into units, execute the initial deployment of owned units.
		//The initial deployment area is the army-side FEBA, get from the battlefield instance."
		_self call ["ConvertManPowerToUnit"];
		
		private _deploymentArea = EGCVAR(battleField,BattleField,instance);
		if(isNil "_deploymentArea")then{
			LOG("(army-InitialDeploy) BattleField instance is nil");
		};
		//NOTE:Need handling if feba not found.
		private _febaList = _deploymentArea call ["FindFebaInside",[_self get "side"]];
		private _msg = format["(InitialDeploy) febaCount %1",count _febaList];
		private _febaListCount = count _febaList;
		LOG(_msg);
		{
			_x params["_unit"];
			private _febaIndex = _forEachIndex % _febaListCount;
			private _initialDeploymentArea = _febaList select _febaIndex;
			private _nilInfo = isNil "_initialDeploymentArea";
			private _msg = format["(Army InitialDeplyoment LoopLog) FebaIndex:%1 FebaisNil:%2",_febaIndex,_nilInfo];
			LOG(_msg);
			_unit call ["InitialDeploy",[_initialDeploymentArea]];
		}forEach(_self get "lowerUnits");
	}],
	["OrderInitialMission",{
		//NOTE:At this stage, all units are ordered on defense missions for now.
		{
			_x params["_unit"];
			private _missionArea = _unit get "deploymentArea";
			private _mission = createHashMapObject[GCLASS(DefenseMission),[_missionArea,_self get "side"]];
			_unit call ["AssignMission",[_mission]];
		}forEach(_self get "lowerUnits");
	}],
	["InstantiateAllUnits",{
		//NOTE:Temporary implementation
		{ _x call ["Instantiate",[]]}forEach(_self get "lowerUnits");
	}],
	["AttackToFront",{
		params["_unit"];
		//private _deploymentArea = _unit get "deploymentArea";
	}]
];