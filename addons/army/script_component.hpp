#define COMPONENT army
#define COMPONENT_BEAUTIFIED Army
#include "\z\ssb\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
#define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_ARMY
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_ARMY
    #define DEBUG_SETTINGS DEBUG_SETTINGS_ARMY
#endif

#include "\z\ssb\addons\main\script_macros.hpp"
#include "\z\ssb\addons\common\script_macros_oop.hpp"