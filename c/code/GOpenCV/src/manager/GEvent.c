//===============================================
#include "GEvent.h"
//===============================================
static GEventO* m_GEventO = 0;
//===============================================
static void GEvent_Init();
static void GEvent_InitKey(int waitKey);
static void GEvent_InitMouse(char* windowName);
//===============================================
static void GEvent_onKey();
static void GEvent_onMouse(int event, int x, int y, int flags, void *params);
//===============================================
static void GEvent_Loop();
static void GEvent_PollEvents();
static void GEvent_Clean();
static int GEvent_Close();
//===============================================
static sGEvent* GEvent_GetEvent();
//===============================================
GEventO* GEvent_New() {
    GEventO* lObj = (GEventO*)malloc(sizeof(GEventO));
    lObj->Delete = GEvent_Delete;
    lObj->Init = GEvent_Init;
    lObj->InitKey = GEvent_InitKey;
    lObj->InitMouse = GEvent_InitMouse;
    lObj->Loop = GEvent_Loop;
    lObj->PollEvents = GEvent_PollEvents;
    lObj->Clean = GEvent_Clean;
    lObj->Close = GEvent_Close;
    lObj->GetEvent = GEvent_GetEvent;
    return lObj;
}
//===============================================
void GEvent_Delete() {
    GEventO* lObj = GEvent();
    if(lObj != 0) {
        free(lObj);
    }
    m_GEventO = 0;
}
//===============================================
GEventO* GEvent() {
    if(m_GEventO == 0) {
        m_GEventO = GEvent_New();
    }
    return m_GEventO;
}
//===============================================
static void GEvent_Init() {
    GEvent()->InitKey(10);
    GEvent()->InitMouse("WINDOW");
}
//===============================================
static void GEvent_InitKey(int waitKey) {
    sGEvent* lEvent = &m_GEventO->m_event;
    sGEventKey* lEventKey = &lEvent->key;
    lEventKey->waitKey = waitKey;
    lEventKey->onFlag = FALSE;
}
//===============================================
static void GEvent_InitMouse(char* windowName) {
    cvSetMouseCallback(windowName, GEvent_onMouse, 0);
}
//===============================================
static void GEvent_onKey() {
    sGEvent* lEvent = &m_GEventO->m_event;
    sGEventKey* lEventKey = &lEvent->key;
    int lKey = cvWaitKey(lEventKey->waitKey);

    if(lKey != -1) {
        lEventKey->onFlag = TRUE;
        lEventKey->key = lKey;
    }
}
//===============================================
static void GEvent_onMouse(int event, int x, int y, int flags, void *params) {
    sGEvent* lEvent = &m_GEventO->m_event;
    sGEventMouse* lEventMouse = &lEvent->mouse;

    lEventMouse->event = event;
    lEventMouse->x = x;
    lEventMouse->y = y;
    lEventMouse->onFlag = TRUE;
}
//===============================================
static void GEvent_Loop() {
    cvWaitKey(0);
}
//===============================================
static void GEvent_PollEvents() {
    GEvent_onKey();
}
//===============================================
static void GEvent_Clean() {
    sGEvent* lEvent = &m_GEventO->m_event;
    sGEventKey* lEventKey = &lEvent->key;
    sGEventMouse* lEventMouse = &lEvent->mouse;

    lEventKey->onFlag = FALSE;
    lEventMouse->onFlag = FALSE;
}
//===============================================
static int GEvent_Close() {
    sGEvent* lEvent = &m_GEventO->m_event;
    sGEventKey* lEventKey = &lEvent->key;
    int lClose = FALSE;

    if(lEventKey->onFlag == TRUE) {
        switch(lEventKey->key) {
        case ' ':
            lClose = TRUE;
            break;
        }
    }

    return lClose;
}
//===============================================
static sGEvent* GEvent_GetEvent() {
    sGEvent* lEvent = &m_GEventO->m_event;
    return lEvent;
}
//===============================================
