//===============================================
#ifndef _GProcessOpenCVEvent_
#define _GProcessOpenCVEvent_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenCVEventO GProcessOpenCVEventO;
//===============================================
struct _GProcessOpenCVEventO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenCVEvent_New();
void GProcessOpenCVEvent_Delete();
GProcessO* GProcessOpenCVEvent();
//===============================================
#endif
//===============================================
