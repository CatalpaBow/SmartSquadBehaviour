#include "script_component.hpp"
private _side = "west";
private _initialManPower = 20;
private _infSquadUnitNames = ["B_Soldier_SL_F","B_soldier_AR_F","B_HeavyGunner_F","B_soldier_AAR_F","B_soldier_M_F","B_Sharpshooter_F","B_soldier_LAT_F","B_medic_F"];
private _armyOrganization = createHashMapObject[GCLASS(ArmyOrganization),[_infSquadUnitNames]];
private _westArmy = createHashMapObject[GCLASS(Army),[_side,_initialManPower,_armyOrganization]];

private _side = "east";
private _infSquadUnitNames = ["O_Soldier_SL_F","O_Soldier_F","O_Soldier_LAT_F","O_soldier_M_F","O_Soldier_TL_F","O_Soldier_AR_F","O_Soldier_A_F","O_medic_F"];
private _armyOrganization = createHashMapObject[GCLASS(ArmyOrganization),[_infSquadUnitNames]];
private _eastArmy = createHashMapObject[GCLASS(Army),[_side,_initialManPower,_armyOrganization]];
[_westArmy,_eastArmy];