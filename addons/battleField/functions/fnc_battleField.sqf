#include "script_component.hpp"
params["_module"];
if!(isServer)exitWith{};
LOG("(BattleFieldModule)Initialilzed");
GVAR(battleFieldModule) = _module;