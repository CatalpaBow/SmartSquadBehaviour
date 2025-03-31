#include "script_component.hpp"
params ["_module"];
_infSquadModules =  [_module,QGVAR(infantrySquadOrganization)]call EFUNC(common,getSyncedModules);
if(count _infSquadModules <= 0 )exitWith{
	_msg = "(army organization)No infantry squad organization module was found synced to the army organization module. The Army Organization Module requires the Infantry Squad Organization Module to be synchronized.";
	LOG(_msg);
};
private _infSquadModule = _infSquadModules#0;
private _members = _infSquadModule getVariable ["members",[]];
createHashMapObject[GCLASS(ArmyOrganization),[_members]];