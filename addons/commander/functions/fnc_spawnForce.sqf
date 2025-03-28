#include "script_component.hpp"
params["_self","_area","_forceStrength"];
private _frontLinePositions = [_area] call FUNC(getFrontLinePositions);
private _posCount = count _frontLinePositions;
private _forceStrengthPerPositions = _forceStrength / _posCount;
//private _forceGroups = [_self,_forceStrengthPerPositions] call FUNC();
{
	[_forceStrengthPerPositions] call FUNC(spawnSquad);
}foreach(_frontLinePositions);

_text = format["SpawnForce Count:%1",_forceStrength];
LOG(_text);