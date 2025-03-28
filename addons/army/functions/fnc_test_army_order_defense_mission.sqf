#include "script_component.hpp"
params["_module"];
private _army = GVAR(armyLst) select 0;
_army call ["ConvertManPowerToUnit"];
_side = "west";
private _missionArea = EGVAR(battleField,bf) get "battleZones" select 0;
private _defenseMission = createHashMapObject[GCLASS(DefenseMission),[_missionArea,_side]];

private _higherUnit = _army get "lowerUnits" select 0;
_higherUnit call ["AssignMission",_defenseMission];
ASSERT_TRUE(_defenseMission == (_higherUnit get "mission"),"Except deffenseMission assgined,but not aassgined.");
_higherUnit get "lowerUnits";

_info = [_higherUnit]call FUNC(show_unit_state);
LOG(_info);