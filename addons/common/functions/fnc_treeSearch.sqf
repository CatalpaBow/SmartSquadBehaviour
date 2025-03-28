#include "script_component.hpp"
_this params["_module","_typeName"];
_rsltList = [];
[_module,_typeName,objNull,_rsltList] call FUNC(treeSearch_recursive);
_rsltList;