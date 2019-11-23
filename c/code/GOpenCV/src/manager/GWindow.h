//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GWindowO GWindowO;
//===============================================
struct _GWindowO {
    void (*Delete)();
    void (*Create)(char* windowName, int flags);
    void (*Remove)(char* windowName);
    void (*RemoveAll)();
};
//===============================================
GWindowO* GWindow_New();
void GWindow_Delete();
GWindowO* GWindow();
//===============================================
#endif
//===============================================
