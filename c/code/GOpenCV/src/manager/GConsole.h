//===============================================
#ifndef _GConsole_
#define _GConsole_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GConsoleO GConsoleO;
//===============================================
struct _GConsoleO {
    void (*Delete)();
    int (*Print)(const char* template, ...);
};
//===============================================
GConsoleO* GConsole_New();
void GConsole_Delete();
GConsoleO* GConsole();
//===============================================
#endif
//===============================================
