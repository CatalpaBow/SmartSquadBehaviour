#include "script_component.hpp"
params["_self"];
LOG("Timing CMDR");
private _forcePool = 1000;
private _forceStrength = 100;

//private _forcePool = _self getVariable "forcePool";




_frontLineAreas = [] call EFUNC(battleField,getFrontLineAreas);
private _areaCount = count _frontLineAreas;
private _forceStrengthOfSend = _forceStrength / _areaCount;
{
	_x params["_area"];
	if(_area getVariable "DefaultSide" == _self getVariable "Side")then{
		[_self,_area,_forceStrengthOfSend]call FUNC(spawnForce);
	}else{
		[_self,_area,_forceStrengthOfSend]call FUNC(sendForce);
	};
}foreach(_frontLineAreas);

/*
private _cntrlrSide =  _battleZone  getVariable ["controllerSide"];

switch(_cntrlrSide)do{
	case "None":{};
	case "West":{};
	case "East":{};
};

[_battleZone] call FUNC();
*/