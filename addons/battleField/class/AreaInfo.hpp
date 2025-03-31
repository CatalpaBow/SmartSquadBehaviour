GCLASS(AreaInfo) = [
	["id",-1],
	["name",""],
    ["position",nil],
	["#create", {	
		params ["_id","_name","_position"];
		_self set ["id",_id];
		_self set ["name",_name];
        _self set ["position",_position];
	}]
];
