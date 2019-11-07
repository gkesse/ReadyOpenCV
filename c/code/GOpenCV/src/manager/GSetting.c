//===============================================
#include "GSetting.h"
#include "GFile2.h"
#include "GString2.h"
#include "GConfig.h"
//===============================================
static GSettingO* m_GSettingO = 0;
//===============================================
static void GSetting_Load(char* file);
//===============================================
GSettingO* GSetting_New() {
    GSettingO* lObj = (GSettingO*)malloc(sizeof(GSettingO));
    lObj->Delete = GSetting_Delete;
    lObj->Load = GSetting_Load;
    return lObj;
}
//===============================================
void GSetting_Delete() {
    GSettingO* lObj = GSetting();
    if(lObj != 0) {
        free(lObj);
    }
    m_GSettingO = 0;
}
//===============================================
GSettingO* GSetting() {
    if(m_GSettingO == 0) {
        m_GSettingO = GSetting_New();
    }
    return m_GSettingO;
}
//===============================================
static void GSetting_Load(char* file) {
	GFile2()->Exist(file);
    FILE* lFile = fopen(file, "r");
    char lBuffer[100];

    while(fgets(lBuffer, sizeof(lBuffer), lFile) != NULL) {
       char* lTrim = GString2()->Trim(lBuffer);
        if(lTrim == 0) {continue;}
        char lFirst = lTrim[0];
        if(lFirst == '#') {GString2()->Free(lTrim); continue;}
        int lCount;
        char** lSplit = GString2()->Split(lTrim, "=", &lCount);
        char* lKey = GString2()->Trim(lSplit[0]);
        char* lValue = GString2()->Trim(lSplit[1]);
        GConfig()->SetData(lKey, lValue);
        GString2()->Free(lTrim);
        GString2()->Free2(lSplit, lCount);
    }
    char* lConfigShow = GConfig()->GetData("CONFIG_SHOW");
    if(GString2()->IsEqual(lConfigShow, "TRUE")) {
        GConfig()->Show();
        printf("\n");
    }
    fclose(lFile);
}
//===============================================
