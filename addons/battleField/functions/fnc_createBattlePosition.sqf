#include "script_component.hpp"
params["_area","_priority","_ownerSide"];

//idCounter preprocess 
if(isNil QGCLASS_VAR(BattlePosition,idCounter))then{
	GCLASS_VAR(BattlePosition,idCounter) = 0;
};
GCLASS_VAR(BattlePosition,idCounter) = (GCLASS_VAR(BattlePosition,idCounter) + 1);
_id = GCLASS_VAR(BattlePosition,idCounter);
//Create bp
_bp = createHashMapObject[GCLASS(BattlePosition),[_area,_priority,_id,_ownerSide]];

//Regsiter bp to list
if(isNil QGCLASS_VAR(BattlePosition,list))then{
	GCLASS_VAR(BattlePosition,list) = createHashMap;
};
GCLASS_VAR(BattlePosition,list) set [_id,_bp];

_bp;