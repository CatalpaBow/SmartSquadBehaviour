#include "script_component.hpp"
params["_unitBase"];
_unitBase get "unitName";
_unitBase get "side";
_unitBase get "location";
_missionInfo = [_unitBase get "mission"]call FUNC(show_mission_state);
format["[UnitInfo]unitName:%1 side:%2 location:%3
			%4",_unitBase get "unitName",_unitBase get "side",_unitBase get "location",_missionInfo];
