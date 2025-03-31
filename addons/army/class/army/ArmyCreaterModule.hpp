GCLASS(ArmyCreaterModule) = [
    ["Create",{
        if(isNil QEGVAR(army,armyModuleList))exitWith{
            throw "(startup)ArmyModuleList is not defined. Army is not construct.";
        };
        private _moduleList = GVAR(armyModuleList);
        private _armyList = _moduleList apply {
            _x params["_module"];
            //GetValueFromModule
            _side = _module getVariable "side";
            _initialManPower = _module getVariable "initialManPower";

            //FindArmyOrganizationModule
            _modules = [_module,QGVAR(armyOrganization)] call EFUNC(common,getSyncedModules);
            if(count _modules <= 0)exitWith{
                _msg = format ["(CreateArmyFromModule)ArmyOrganization module has not been found. Ensure it is synchronized correctly."];
                LOG(_msg);
            };
            if(count _modules > 1)then{
                _msg = format["(CreateArmyFromModule)Multiple army organization module synced to army module.Only use army organization module which first of found."]
            };
            _firstFoundModule = _modules select 0;
            _armyOrganization = [_firstFoundModule] call FUNC(create_army_organization_from_module);

            //Create
            createHashMapObject[GCLASS(Army),[_side,_initialManPower,_armyOrganization]];
        };
        _armyList;
    }]
];