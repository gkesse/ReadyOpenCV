//===============================================
#ifndef _GWaitKey_
#define _GWaitKey_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GWaitKeyO GWaitKeyO;
//===============================================
struct _GWaitKeyO {
    void (*Delete)();
    void (*Loop)();
    int (*Key)(int wait);
};
//===============================================
GWaitKeyO* GWaitKey_New();
void GWaitKey_Delete();
GWaitKeyO* GWaitKey();
//===============================================
#endif
//===============================================
