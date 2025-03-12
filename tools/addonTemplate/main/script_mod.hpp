// COMPONENT should be defined in the script_component.hpp and included BEFORE this hpp

#define MAINPREFIX replacement_MAINPREFIX
#define PREFIX replacement_PREFIX
#define SUBPREFIX addons

#include "script_version.hpp"

// MINIMAL required version for the Mod. Components can specify others..
#define REQUIRED_VERSION 2.00
#define REQUIRED_CBA_VERSION {3,15,8}


#ifdef COMPONENT_BEAUTIFIED
    #define COMPONENT_NAME QUOTE(replacement_MODNAME - COMPONENT_BEAUTIFIED)
#else
    #define COMPONENT_NAME QUOTE(replacement_MODNAME - COMPONENT)
#endif// COMPONENT should be defined in the script_component.hpp and included BEFORE this hpp