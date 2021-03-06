//===============================================
#include "GOptions.h"
#include "GString2.h"
#include "GConfig.h"
//===============================================
static GOptionsO* m_GOptionsO = 0;
//===============================================
static void GOptions_GetArgs(int argc, char** argv);
//===============================================
GOptionsO* GOptions_New() {
    GOptionsO* lObj = (GOptionsO*)malloc(sizeof(GOptionsO));
    lObj->Delete = GOptions_Delete;
    lObj->GetArgs = GOptions_GetArgs;
    return lObj;
}
//===============================================
void GOptions_Delete() {
    GOptionsO* lObj = GOptions();
    if(lObj != 0) {
        free(lObj);
    }
    m_GOptionsO = 0;
}
//===============================================
GOptionsO* GOptions() {
    if(m_GOptionsO == 0) {
        m_GOptionsO = GOptions_New();
    }
    return m_GOptionsO;
}
//===============================================
static void GOptions_GetArgs(int argc, char** argv) {
    GConfig()->SetData("PROCESS", "HELP");
    GConfig()->SetData("OPTION_1", "");
    GConfig()->SetData("OPTION_2", "");

    if(argc >= 2) {
        char* lProcess = GString2()->ToUpper(argv[1]);
        GConfig()->SetData("PROCESS", lProcess);
    }
    if(argc >= 3) {
        GConfig()->SetData("OPTION_1", argv[2]);
    }
    if(argc >= 4) {
        GConfig()->SetData("OPTION_2", argv[3]);
    }

}
//===============================================
