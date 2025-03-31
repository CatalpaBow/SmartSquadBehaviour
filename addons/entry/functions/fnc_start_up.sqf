#include "script_component.hpp"
try{
	//Initialize
	LOG("(startup)[Startup BattleFieldEnviroment]");
	_rslt = call FUNC(initialize);
	if(_rslt == false)exitWith{
		LOG("(startup) initialize battleFeildEnveiroment failed.");
	};
	LOG("(startup) initialize battleFeildEnveiroment sucsesfully");


	LOG("(startup) Excute deployment of army.");
	{ _x call ["InitialDeploy"]}forEach(EGCVAR(army,Army,instanceList));
} catch {
	ERROR(_exception);
};