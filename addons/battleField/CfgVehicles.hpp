class CBA_Extended_EventHandlers_base;
class CfgVehicles {
    class EGVAR(modules,moduleBase);
    class GVAR(battleField): EGVAR(modules,moduleBase) {
        category = "SmartSquadBehaviour";
        displayName = "BattleField";
        function = QFUNC(battleField);
    };
    class GVAR(battleZone): EGVAR(modules,moduleBase) {
        category = "SmartSquadBehaviour";
        displayName = "BattleZone";
        function = "";
        class AttributesBase;
        class Attributes : AttributesBase{
            class Edit;
            class Combo;
            class Priority : Edit{
                property     = QGVAR(Priority);
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
