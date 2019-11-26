//===============================================
#ifndef _GEvent_
#define _GEvent_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GEventO GEventO;
//===============================================
struct _GEventO {
    void (*Delete)();
    void (*Init)(int waitKey);
    void (*PollEvents)();
    void (*Clean)();
    void (*Loop)();
    sGEvent* (*GetEvent)();
    sGEvent m_event;
};
//===============================================
GEventO* GEvent_New();
void GEvent_Delete();
GEventO* GEvent();
//===============================================
#endif
//===============================================
