/**
Fast Recompiling via function
**/
// #define DISABLE_COMPILE_CACHE
// To Use: [] call replacement_PREFIX_PREP_RECOMPILE;

#ifdef DISABLE_COMPILE_CACHE
    #define LINKFUNC(x) {_this call FUNC(x)}
    #define PREP_RECOMPILE_START    if (isNil "replacement_upper_PREFIX_PREP_RECOMPILE") then {replacement_upper_PREFIX_RECOMPILES = []; replacement_upper_PREFIX_PREP_RECOMPILE = {{call _x} forEach replacement_upper_PREFIX_RECOMPILES;}}; private _recomp = {
    #define PREP_RECOMPILE_END      }; call _recomp; replacement_upper_PREFIX_RECOMPILES pushBack _recomp;
#else
    #define LINKFUNC(x) FUNC(x)
    #define PREP_RECOMPILE_START ; /* disabled */
    #define PREP_RECOMPILE_END ; /* disabled */
#endif