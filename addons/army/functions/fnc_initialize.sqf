#include "script_component.hpp"
//Construct Army
if(isNil QEGVAR(army,armyModuleList))exitWith{
	LOG("(startup)ArmyModuleList is not defined. Army is not construct.");
	false;
};
_armyModuleList = EGVAR(army,armyModuleList);
if(count _armyModuleList <= 0)exitWith{
	LOG("(startup)The number of elements in the army module list is 0.Army is not construct.");
	false;
};
EGCVAR(army,Army,instanceList) = _armyModuleList apply {_x call EFUNC(army,create_army_from_module)};
LOG("(startup)Army instance has been successfully cunstruct.");
true;