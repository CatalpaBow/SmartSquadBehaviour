class CBA_Extended_EventHandlers_base;
class CfgVehicles {
    class Logic;
    class Module_F:Logic{
		class AttributesBase{
			class Default;
			class Edit;					// Default edit box (i.e. text input field)
			class Combo;				// Default combo box (i.e. drop-down menu)
			class Checkbox;				// Default checkbox (returned value is Boolean)
			class CheckboxNumber;		// Default checkbox (returned value is Number)
			class ModuleDescription;	// Module description
			class Units;				// Selection of units on which the module is applied
		};
		// Description base classes (for more information see below):
		class ModuleDescription
		{
			class AnyBrain;
		};
    };
    class GVAR(moduleBase): Module_F {
        author = ECSTRING(main,Author);
        function = "";
        scope = 2;
        scopeCurator = 2;
        class EventHandlers {
            init = QUOTE(_this call FUNC(initModule));
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers_base {};
        };

        class AttributesBase;
    }; 
};