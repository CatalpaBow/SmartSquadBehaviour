#include "script_component.hpp"
params["_module"];
if(isNil QGVAR(cmdrs))then{
	GVAR(cmdrs) = [];
	GVAR(cmdrs) pushBack _module;
};
[FUNC(startup),_module] call CBA_fnc_execNextFrame;