class CBA_Extended_EventHandlers_base;
class CfgVehicles {
    class EGVAR(modules,moduleBase);
    class GVAR(battleField): EGVAR(modules,moduleBase) {
        category = "SmartSquadBehaviour";
        displayName = "BattleField";
        function = QFUNC(battleField);
        class AttributesBase;
        class Attributes : AttributesBase{
            class Edit;
            class Name : Edit{
                property     = QGVAR(name);
                displayName  = "Name";
                tooltip      = "Name of battle field";
                typeName     = "STRING";    
                defaultValue = """BattleField""";
            };
        };
    };
    class GVAR(battleZone): EGVAR(modules,moduleBase) {
        category = "SmartSquadBehaviour";
        displayName = "BattleZone";
        function = "";
        class AttributesBase;
        class Attributes : AttributesBase{
            class Edit;
            class Combo;
            class Name : Edit{
                property     = QGVAR(name);
                displayName  = "Name";
                tooltip      = "Name of battle zone";
                typeName     = "STRING";    
                defaultValue = """""";
            };
            class Priority : Edit{
                property     = QGVAR(Priority);
                displayName  = "Priority";
                tooltip      = "Low:OFPOR High:BLUFOR";
                typeName     = "NUMBER";
                defaultValue = "1";
            };         

            class OwnerSide: Combo{
                property     = QGVAR(ownerSide);
                displayName  = "OwnerSide";
                tooltip      = "WEST,EAST,None";
                typeName     = "STRING";
                defaultValue = """None""";
				// Listbox items
				class Values
				{
                    class None  { name = "None"; value = "none";};
					class West	{ name = "West"; value = "west";};
					class East	{ name = "East"; value = "east";};
				};
            };
        };
    };
    class GVAR(battlePosition): EGVAR(modules,moduleBase) {
        category = "SmartSquadBehaviour";
        displayName = "BattlePosition";
        function = "";
        icon = "\a3\ui_f\data\logos\a_64_ca.paa";
        class AttributesBase;
        class Attributes:AttributesBase{
            class Edit;
            class Combo;
            class Name : Edit{
                property     = QGVAR(name);
                displayName  = "Name";
                tooltip      = "Name of battle position";
                typeName     = "STRING";    
                defaultValue = """""";
            };
            class Priority: Edit{
                property     = QGVAR(priority);
                displayName  = "Priority";
                tooltip      = "Low:OFPOR High:BLUFOR";
                typeName     = "NUMBER";
                defaultValue = "1";
            };
            class OwnerSide: Combo{
                property     = QGVAR(ownerSide);
                displayName  = "OefaultSide";
                tooltip      = "WEST,EAST,None";
                typeName     = "STRING";
                defaultValue = """None""";
				// Listbox items
				class Values{
                    class None  { name = "None"; value = "none";};
					class West	{ name = "West"; value = "west";};
					class East	{ name = "East"; value = "east";};
				};
            };
        };
    }; 
};  
