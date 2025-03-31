#include "script_component.hpp"
params["_infSquadModule"];
private _syncObjs = synchronizedObjects _infSquadModule;
private _manObjs = _syncObjs select {_x isKindOf "AllVehicles"};

if(count _manObjs <= 0)exitWith{
	LOG("(army organization module)No synchronized infantry units found.");
	_infSquadModule setVariable["members",[]];
};
if(count _manObjs > 1)then{
	LOG("(army organization module)Multiple synchronized infantry units found.
			Only one infantry group within the synchronized infantry units will be registered as an organization in the Infantry Squad Organization Module.
			If you want to register a specific infantry squad group only, ensure that only one infantry unit is synchronized with the organization module.");
};
private _man = _manObjs select 0;
private _unitClassNames = (units _man) apply {typeOf _x };
deleteVehicle units _man;
_infSquadModule setVariable["members",_unitClassNames];