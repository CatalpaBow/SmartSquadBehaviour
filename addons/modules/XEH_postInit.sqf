#include "script_component.hpp"
{
	_x hideObject true;
	private _function = getText (configOf _x >> "function");
	if (_function isEqualTo "") then { continue};

	if (isNil _function) then {
		_function = compile _function;
	} else {
		_function = missionNamespace getVariable _function;
	};
	[_function, _x] call CBA_fnc_directCall;
	 
}forEach(GVAR(moduleInitCollection));