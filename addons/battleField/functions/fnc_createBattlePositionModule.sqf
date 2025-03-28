#include "script_component.hpp"
params["_module"];
LOG("CrateBattlePositionModule called");
_pos = getPos _module;
_area = createHashMapObject [GCLASS(AreaInfo),[_pos]];
_priority = _module getVariable "priority";
_ownerSide = _module getVariable "ownerSide";
[_area,_priority,_ownerSide] call FUNC(createBattlePosition);