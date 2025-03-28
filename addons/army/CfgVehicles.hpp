class CBA_Extended_EventHandlers_base;
class CfgVehicles {
    class EGVAR(modules,moduleBase);
    class GVAR(army): EGVAR(modules,moduleBase) {
        category = "SmartSquadBehaviour";
        displayName = "Army";
        function = QFUNC(army);
        
        class AttributesBase;
        class Attributes : AttributesBase{
            class Combo;
            class Side : Combo{
                property     = QGVAR(Side);
                displayName  = "Side";
                tooltip      = "WEST,EAST";
                typeName     = "STRING";
                defaultValue = """west""";
				// Listbox items
				class Values{
					class West	{ name = "West"; value = "west";};
					class East	{ name = "East"; value = "east";};
				};
            };
            class Edit;
            class InitialManPower : Edit{
                property     = QGVAR(initialManPower);
                displayName  = "InitialManPower";
                tooltip      = "Manpower at the start of the mission";
                typeName     = "NUMBER";
                defaultValue = "10";
            };     
        };
    };
    class GVAR(armyOrganization): EGVAR(modules,moduleBase) {
        category = "SmartSquadBehaviour";
        displayName = "ArmyOrganization";
        function = "";
    };    
    class GVAR(infantrySquadOrganization): EGVAR(modules,moduleBase) {
        category = "SmartSquadBehaviour";
        displayName = "InfantrySquadOrganization";
        function = "";
    };

    class GVAR(armyCommander): EGVAR(modules,moduleBase) {
        category = "SmartSquadBehaviour";
        displayName = "ArmyCommander";
        function = "";
        class AttributesBase;
        class Attributes : AttributesBase{
            class Combo;
            class Side : Combo{
                property     = QGVAR(Side);
                displayName  = "Side";
                tooltip      = "WEST,EAST";
                typeName     = "STRING";
                defaultValue = """West""";
				// Listbox items
				class Values
				{
					class West	{ name = "West"; value = "west";};
					class East	{ name = "East"; value = "east";};
				};
            };
        };
    };
};  
