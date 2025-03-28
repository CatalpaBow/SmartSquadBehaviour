#include "script_component.hpp"
params["_treeCtl","_path","_unitList"];
private _parentIndex = count _path;
private _nextPath = _path + [0];
{
	_nextPath set [_parentIndex,_forEachIndex];
	_x params["_unit"];
	private _name = _unit get "unitName";
	LOG(_name);
	_treeCtl tvAdd[_path,_name];
	if("Higher" in (_unit get "#type"))then{
		private _lowerUnits = _unit get "lowerUnits";
		[_treeCtl,_nextPath,_lowerUnits] call FUNC(recursion);
	};
	
}forEach(_unitList);
