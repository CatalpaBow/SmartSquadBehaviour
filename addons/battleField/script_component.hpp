#define COMPONENT battleField
#define COMPONENT_BEAUTIFIED Battlefield
#include "\z\ssb\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_BATTLEFIELD
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_BATTLEFIELD
    #define DEBUG_SETTINGS DEBUG_SETTINGS_BATTLEFIELD
#endif

#include "\z\ssb\addons\main\script_macros.hpp"
#include "\z\ssb\addons\common\script_macros_oop.hpp"