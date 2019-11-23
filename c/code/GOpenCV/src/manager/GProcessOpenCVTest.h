//===============================================
#ifndef _GProcessOpenCVTest_
#define _GProcessOpenCVTest_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenCVTestO GProcessOpenCVTestO;
//===============================================
struct _GProcessOpenCVTestO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenCVTest_New();
void GProcessOpenCVTest_Delete();
GProcessO* GProcessOpenCVTest();
//===============================================
#endif
//===============================================
