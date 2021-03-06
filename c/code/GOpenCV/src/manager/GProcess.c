//===============================================
#include "GProcess.h"
#include "GProcessHelp.h"
#include "GProcessOpenCVImage.h"
#include "GProcessOpenCVEvent.h"
#include "GString2.h"
#include "GConfig.h"
//===============================================
GProcessO* GProcess_New() {
    GProcessO* lObj = (GProcessO*)malloc(sizeof(GProcessO));
    lObj->m_child = 0;
    return lObj;
}
//===============================================
void GProcess_Delete(GProcessO* obj) {
    if(obj != 0) {
        if(obj->m_child != 0) {
            free(obj->m_child);
        }
        free(obj);
    }
}
//===============================================
GProcessO* GProcess() {
    char* lKey = GConfig()->GetData("PROCESS");
    if(GString2()->IsEqual(lKey, "HELP")) return GProcessHelp();
    if(GString2()->IsEqual(lKey, "IMAGE")) return GProcessOpenCVImage();
    if(GString2()->IsEqual(lKey, "EVENT")) return GProcessOpenCVEvent();
    return GProcessHelp();
}
//===============================================
