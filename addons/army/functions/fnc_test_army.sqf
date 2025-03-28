#include "script_component.hpp"
[] call SSB_PREP_RECOMPILE;
[] call ssb_army_fnc_declaraClass;
[] call ssb_battleField_fnc_declaraClass;

GVAR(debugArmyList) = call ssb_army_fnc_create_army_test;
private _armyWestEast = GVAR(debugArmyList);
{
	_x params["_army"];
	_army call ["InitialDeploy"];
	_army call ["OrderInitialMission"];
	_army call ["InstantiateAllUnits"];
	/*
	private _higherUnits = (_army get "lowerUnits");
	private _lowerUnits = (_higherUnits select 0) get "lowerUnits";

	private _higherUnitsName = _higherUnits apply{_x get "unitName"};
	private _higherUnitsMissionType = _higherUnits apply {_x get "mission" get "type"};
	private _higherUnitsDeploymentArea = _higherUnits apply{_x get "deploymentArea"};

	private _lowerUnitsName = _lowerUnits apply{_x get "unitName"};
	private _lowerUnitsMissionType = _lowerUnits apply {_x get "mission" get "type"};
	private _lowerUnitsDeploymentArea = _lowerUnits apply{_x get "deploymentArea"};
	*/
}forEach(_armyWestEast);
[_armyWestEast] call FUNC(debug_display);