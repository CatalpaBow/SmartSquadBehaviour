#include "script_component.hpp"
params["_bpModuleList","_refPriority"];
_bpLowList = [];_bpSameList = [];_bpHighList = [];
{
	_syncedModulePriority = _x getVariable("priority");
	switch (true)do
	{
		//Hack
		case (_syncedModulePriority < _refPriority): {_bpLowList pushBack (_x getVariable "BPClassInstance" get "id")};
		case (_syncedModulePriority == _refPriority):{_bpSameList pushBack (_x getVariable "BPClassInstance" get "id")};
		case (_syncedModulePriority > _refPriority) :{_bpHighList pushBack (_x getVariable "BPClassInstance" get "id")};
	};
}forEach(_bpModuleList);
[_bpLowList,_bpSameList,_bpHighList];