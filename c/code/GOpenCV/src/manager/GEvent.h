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
    void (*Init)();
    void (*InitKey)(int waitKey);
    void (*InitMouse)(char* windowName);
    void (*PollEvents)();
    void (*Clean)();
    int (*Close)();
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
