GCLASS(BattleFieldCreaterModule) = [
	["Create",{
		if(isNil QEGVAR(battleField,battleFieldModule))exitWith{
			_msg = format["The BattleFieldModule variable is undefined. Is the module not placed? VariableName:%1",QEGVAR(battleField,battleFieldModule)];
			throw _msg;
		};
		//CreateBattleField
		private _bfModule = EGVAR(battleField,battleFieldModule);
		private _pos = getPos _bfModule;
		private _bf = createHashMapObject[GCLASS(BattleField),[_pos]];

		//SetBattleZones
		private _bzModules = [_bfModule,QGVAR(battleZone)] call EFUNC(common,getSyncedModules);
		private _bzCreater = createHashMapObject[GCLASS(BattleZoneCreaterModule)];
		{
			_bzCreater set ["module",_x];
			_bf call ["NewBattleZone",[_bzCreater]];
		}forEach(_bzModules);
		_bf;
	}]
];
