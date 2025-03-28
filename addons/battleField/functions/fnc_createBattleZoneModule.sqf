#include "script_component.hpp"
params["_module"];
//AreaInfo
_areaPos = getPos _module;
_areaInfo = createHashMapObject[GVAR(class_AreaInfo),_areaPos];
//AreaPriority
_baPriority = _module getVariable "priority";
//OwnerSide
_baOwnerSide = _module getVariable "ownerSide";
//BattlePositionList
_bpModuleList = [_module,QGVAR(battlePosition)] call EFUNC(common,treeSearch);
_bpClassList = _bpModuleList apply {[_x] call FUNC(createBattlePositionModule)};
_bpNameList = _bpModuleList apply {typeOf _x};
{
	_x params["_bpModule"];
	_name = typeOf _bpModule;
}forEach(_bpModuleList);
//Set BattlePosition Connection
{_x setVariable ["BPClassInstance",_bpClassList select _forEachIndex]}forEach(_bpModuleList); //Hack: Tying class to module for sort process.

{
	_x params["_bpModule"];
	_syncedBPs = [_bpModule,QGVAR(battlePosition)] call EFUNC(common,getSyncedModules);
	_refPriority = _bpModule getVariable "priority";
	_sortedList = [_syncedBPs,_refPriority] call FUNC(lowHighPrioritySort);//Hack: Use BPClassInstance variable in sort process.
	(_bpClassList select _forEachIndex) call ["SetBPConection",_sortedList]; 
}forEach(_bpModuleList);
//{_x setVariable ["BPClassInstance",nil] }forEach(_bpModuleList);//Hack: Clear tying.
createHashMapObject[GCLASS(BattleZone),[_areaInfo,_bpClassList,_baPriority,_baOwnerSide]];