#include "script_component.hpp"
_this params["_module","_typeName",["_previous",objNull],"_rsltList"];
_syncedObjs = synchronizedObjects _module;
_childModules = _syncedObjs select {typeOf _x  == _typeName};
{
	if(_previous == _x)then{
		continue;
	};
	_rsltList pushBack _x;
	[_x,_typeName,_module,_rsltList] call FUNC(treeSearch_recursive);
}forEach(_childModules);	
_rsltList;