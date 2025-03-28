#include "script_component.hpp"
/*
 * Author: mharis001
 * Initializes modules created by Zeus. Simplified to only execute function where local.
 * Function is executed one frame later in an unscheduled environment.
 *
 * Arguments:
 * 0: Logic <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [LOGIC] call zen_modules_fnc_initModule
 *
 * Public: No
 */
params ["_logic"];
GVAR(moduleInitCollection) pushBack (_this select 0);