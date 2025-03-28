#include "script_component.hpp"
params["_module"];
if!(isServer)exitWith{};
LOG("(ArmyModule)Initialilzed");
if(isNil QGVAR(armyModuleList))then{
	GVAR(armyModuleList) = [];
};
GVAR(armyModuleList) pushBack _module;