#include "script_component.hpp"
params ["_module"];
_infSquadModules =  [_module,QGVAR(infantrySquadOrganization)]call EFUNC(common,getSyncedModules);
if(count _infSquadModules <= 0 )exitWith{
	_msg = "(army organization)No infantry squad organization module was found synced to the army organization module. The Army Organization Module requires the Infantry Squad Organization Module to be synchronized.";
	LOG(_msg);
};
_infSquadModule = _infSquadModules#0;

private _syncObjs = synchronizedObjects _infSquadModule;
private _manObjs = _syncObjs select {_x isKindOf "AllVehicles"};
if(count _manObjs <= 0)exitWith{
	LOG("(army organization)No synchronized infantry units found.");
};
if(count _manObjs > 1)then{
	LOG("(army organization)Multiple synchronized infantry units found.
			Only one infantry group within the synchronized infantry units will be registered as an organization in the Infantry Squad Organization Module.
			If you want to register a specific infantry squad group only, ensure that only one infantry unit is synchronized with the organization module.");
};
private _man = _manObjs select 0;
private _unitClassNames = (units _man) apply {typeOf _x };
deleteVehicle units _man;
createHashMapObject[GCLASS(ArmyOrganization),[_unitClassNames]];