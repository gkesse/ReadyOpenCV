//===============================================
#ifndef _GOpenCVEvent_
#define _GOpenCVEvent_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GOpenCVEventO GOpenCVEventO;
//===============================================
struct _GOpenCVEventO {
    void (*Delete)();
    void (*Run)();
    int m_continue;
};
//===============================================
GOpenCVEventO* GOpenCVEvent_New();
void GOpenCVEvent_Delete();
GOpenCVEventO* GOpenCVEvent();
//===============================================
#endif
//===============================================
