#include "script_component.hpp"
if!(call EFUNC(army,initialize))then{
	false;
};
if!(call EFUNC(battleField,initialize))then{
	false;	
};
true;