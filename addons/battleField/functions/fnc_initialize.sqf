#include "script_component.hpp"
private _bfCreater = createHashMapObject [GCLASS(BattleFieldCreaterModule)];
EGCVAR(battleField,BattleField,instance) = _bfCreater call ["Create"];
true;