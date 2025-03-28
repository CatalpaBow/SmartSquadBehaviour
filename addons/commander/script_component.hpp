#define COMPONENT commander
#define COMPONENT_BEAUTIFIED Commander
#include "\z\ssb\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_COMMANDER
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_COMMANDER
    #define DEBUG_SETTINGS DEBUG_SETTINGS_COMMANDER
#endif

#include "\z\ssb\addons\main\script_macros.hpp"
