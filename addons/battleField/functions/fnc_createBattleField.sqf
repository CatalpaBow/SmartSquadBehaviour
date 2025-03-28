#include "script_component.hpp"
params ["_bfModule"];
//BattleZones
_baModules = [_bfModule,QGVAR(battleZone)] call EFUNC(common,getSyncedModules);
_battleZones = _baModules apply {[_x] call FUNC(createBattleZoneModule)};

//AreaInfo
_areaPos = getPos _bfModule;
_areaInfo = createHashMapObject[GCLASS(AreaInfo),_areaPos];
createHashMapObject[GCLASS(BattleField),[_areaInfo,_battleZones]];