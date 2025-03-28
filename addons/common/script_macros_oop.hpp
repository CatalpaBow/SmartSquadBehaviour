#define GCLASS(var1) TRIPLES(ADDON,class,var1)
#define EGCLASS(var1,var2) DOUBLES(DOUBLES(PREFIX,var1),DOUBLES(class,var2))
#define GCLASS_VAR(var1,var2) DOUBLES(DOUBLES(ADDON,class),DOUBLES(var1,var2))
#define GCVAR(var1,var2) DOUBLES(DOUBLES(ADDON,class),DOUBLES(var1,var2))
#define EGCVAR(var1,var2,var3) DOUBLES(DOUBLES(PREFIX,var1),TRIPLES(class,var2,var3))
#define QGCLASS_VAR(var1,var2) QUOTE(GCLASS_VAR(var1,var2))

#define NEWGCLASS(var1) createHashMapObject[GCLASS(var1)]
#define NEWGCLASS_ARG(var1,var2) createHashMapObject[GCLASS(var1),var2]