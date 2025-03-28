#include "script_component.hpp"
if(isNil QEGVAR(battleField,battleFieldModule))exitWith{
	LOG("(startup)battleFieldModule is not defined. BattleField is not construct.");
	false;
};
EGCVAR(battleField,BattleField,instance) = [EGVAR(battleField,battleFieldModule)] call EFUNC(battleField,createBattleField);
LOG("(startup)BattleField instance has been successfully cunstruct.");
true;