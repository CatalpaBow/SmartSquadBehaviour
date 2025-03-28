#include "script_component.hpp"
params["_armyList"];

if(isNil "_armyList")then{
	_armyList = GCVAR(Army,instanceList);
};
_dbgDis = createHashMapObject [GCLASS(DebugDisplay),[_armyList]];
GVAR(dbgDis) = _dbgDis;
_dbgDis call ["Open"];