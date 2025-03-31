GCLASS(UnitBase) = [
	["#type", "BaseUnit"],
	["unitName",""], //str
	["side",""], //str
	["deploymentArea",nil],
	["mission",nil], //Mission
	["#create",{
		params["_unitName","_side","_deploymentArea","_mission"];
		_self set ["unitName",_unitName];
		_self set ["side",_side];
		_self set ["deploymentArea",_deploymentArea];
		_self set ["mission",_mission];
	}],
	["AssignMission",{}],
	["SubUnitCount",{}]
];