#include "script_component.hpp"
params["_module","_moduleType"];
private _syncObjs = synchronizedObjects _module;
private _modules = _syncObjs select {typeOf _x  == _moduleType};
_modules;