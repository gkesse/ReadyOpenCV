//===============================================
#include "GEvent.h"
//===============================================
static GEventO* m_GEventO = 0;
//===============================================
static void GEvent_Init(int waitKey);
static void GEvent_Loop();
static void GEvent_PollEvents();
static void GEvent_Clean();
static sGEvent* GEvent_GetEvent();
//===============================================
GEventO* GEvent_New() {
    GEventO* lObj = (GEventO*)malloc(sizeof(GEventO));
    lObj->Delete = GEvent_Delete;
    lObj->Init = GEvent_Init;
    lObj->Loop = GEvent_Loop;
    lObj->PollEvents = GEvent_PollEvents;
    lObj->Clean = GEvent_Clean;
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
static void GEvent_Init(int waitKey) {
	sGEvent* lEvent = &m_GEventO->m_event;
	sGEventKey* lEventKey = &lEvent->key;
    lEventKey->waitKey = waitKey;
    lEventKey->onFlag = FALSE;
}
//===============================================
static void GEvent_Loop() {
	cvWaitKey(0);
}
//===============================================
static void GEvent_PollEvents() {
	sGEvent* lEvent = &m_GEventO->m_event;
	sGEventKey* lEventKey = &lEvent->key;
    int lKey = cvWaitKey(lEventKey->waitKey);
    if(lKey != -1) {
    	lEventKey->onFlag = TRUE;
    	lEventKey->key = lKey;
    }
}
//===============================================
static void GEvent_Clean() {
	sGEvent* lEvent = &m_GEventO->m_event;
	sGEventKey* lEventKey = &lEvent->key;
	lEventKey->onFlag = FALSE;
}
//===============================================
static sGEvent* GEvent_GetEvent() {
	sGEvent* lEvent = &m_GEventO->m_event;
	return lEvent;
}
//===============================================
