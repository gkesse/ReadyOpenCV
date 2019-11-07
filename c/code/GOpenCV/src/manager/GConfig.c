//===============================================
#include "GConfig.h"
#include "GConfigTemplate.h"
#include "GString2.h"
//===============================================
GConfigO* GConfig_New() {
    GConfigO* lObj = (GConfigO*)malloc(sizeof(GConfigO));
    lObj->m_child = 0;
    return lObj;
}
//===============================================
void GConfig_Delete(GConfigO* obj) {
    if(obj != 0) {
        if(obj->m_child != 0) {
            free(obj->m_child);
        }
        free(obj);
    }
}
//===============================================
GConfigO* GConfig() {
    char* lKey = "TEMPLATE";
    if(GString2()->IsEqual(lKey, "TEMPLATE")) return GConfigTemplate();
    return GConfigTemplate();
}
//===============================================

