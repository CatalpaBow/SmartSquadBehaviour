#include "script_component.hpp"
[] call SSB_PREP_RECOMPILE;
[] call ssb_army_fnc_declaraClass;
[] call ssb_battleField_fnc_declaraClass;

private _bfCreater = createHashMapObject[EGCLASS(battleField,BattleFieldCreaterModule)];
private _bf = _bfCreater call ["Create"];

private _armyCreater = createHashMapObject[EGCLASS(army,ArmyCreaterModule)];
private _armyList = _armyCreater call ["Create"];

GVAR(dbgArmy) = _armyList;
{
	_x call ["InitialDeploy",[_bf]];
	_x call ["OrderInitialMission",[_bf]];
	_x call ["InstantiateAllUnits"];
}forEach(_armyList);
private _dbd = createHashMapObject[EGCLASS(army,DebugDisplay),[_armyList]];
_dbd call ["Open"];
_armyList;