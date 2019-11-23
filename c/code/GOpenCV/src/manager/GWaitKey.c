//===============================================
#include "GWaitKey.h"
//===============================================
static GWaitKeyO* m_GWaitKeyO = 0;
//===============================================
static void GWaitKey_Loop();
static int GWaitKey_Key(int wait);
//===============================================
GWaitKeyO* GWaitKey_New() {
    GWaitKeyO* lObj = (GWaitKeyO*)malloc(sizeof(GWaitKeyO));
    lObj->Delete = GWaitKey_Delete;
    lObj->Loop = GWaitKey_Loop;
    lObj->Key = GWaitKey_Key;
    return lObj;
}
//===============================================
void GWaitKey_Delete() {
    GWaitKeyO* lObj = GWaitKey();
    if(lObj != 0) {
        free(lObj);
    }
    m_GWaitKeyO = 0;
}
//===============================================
GWaitKeyO* GWaitKey() {
    if(m_GWaitKeyO == 0) {
        m_GWaitKeyO = GWaitKey_New();
    }
    return m_GWaitKeyO;
}
//===============================================
static void GWaitKey_Loop() {
    cvWaitKey(0);
}
//===============================================
static int GWaitKey_Key(int wait) {
    int lKey = cvWaitKey(wait);
    return lKey;
}
//===============================================
