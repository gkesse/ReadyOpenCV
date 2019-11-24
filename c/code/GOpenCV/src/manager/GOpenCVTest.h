//===============================================
#ifndef _GOpenCVTest_
#define _GOpenCVTest_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GOpenCVTestO GOpenCVTestO;
//===============================================
struct _GOpenCVTestO {
    void (*Delete)();
    void (*Run)();
};
//===============================================
GOpenCVTestO* GOpenCVTest_New();
void GOpenCVTest_Delete();
GOpenCVTestO* GOpenCVTest();
//===============================================
#endif
//===============================================
