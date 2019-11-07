//===============================================
#include "GConsole.h"
//===============================================
static GConsoleO* m_GConsoleO = 0;
//===============================================
GConsoleO* GConsole_New() {
    GConsoleO* lObj = (GConsoleO*)malloc(sizeof(GConsoleO));
    lObj->Delete = GConsole_Delete;
    lObj->Print = printf;
    return lObj;
}
//===============================================
void GConsole_Delete() {
    GConsoleO* lObj = GConsole();
    if(lObj != 0) {
        free(lObj);
    }
    m_GConsoleO = 0;
}
//===============================================
GConsoleO* GConsole() {
    if(m_GConsoleO == 0) {
        m_GConsoleO = GConsole_New();
    }
    return m_GConsoleO;
}
//===============================================
