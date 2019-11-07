//===============================================
#include "GConfigTemplate.h"
#include "GConsole.h"
//===============================================
typedef char* GCHAR_PTR;
//===============================================
GDECLARE_MAP(GConfigTemplate, GCHAR_PTR, GCHAR_PTR)
GDEFINE_MAP(GConfigTemplate, GCHAR_PTR, GCHAR_PTR)
//===============================================
static GConfigO* m_GConfigTemplateO = 0;
//===============================================
static void GConfigTemplate_Clear();
static void GConfigTemplate_Remove(char* key);
static void GConfigTemplate_SetData(char* key, char* value);
static char* GConfigTemplate_GetData(char* key);
static int GConfigTemplate_Size();
static void GConfigTemplate_Show();
//===============================================
static int GConfigTemplate_MapEqual(char* key1, char* key2);
static void GConfigTemplate_MapShow(char* key, char* value);
//===============================================
GConfigO* GConfigTemplate_New() {
    GConfigO* lParent = GConfig_New();
    GConfigTemplateO* lChild = (GConfigTemplateO*)malloc(sizeof(GConfigTemplateO));

    lChild->m_parent = lParent;
    lChild->m_dataMap = GMap_New_GConfigTemplate_GCHAR_PTR_GCHAR_PTR();

    lParent->m_child = lChild;
    lParent->Delete = GConfigTemplate_Delete;
    lParent->Clear = GConfigTemplate_Clear;
    lParent->Remove = GConfigTemplate_Remove;
    lParent->SetData = GConfigTemplate_SetData;
    lParent->GetData = GConfigTemplate_GetData;
    lParent->Size = GConfigTemplate_Size;
    lParent->Show = GConfigTemplate_Show;
    return lParent;
}
//===============================================
void GConfigTemplate_Delete() {
    GConfigTemplate_Clear();
    GConfig_Delete(m_GConfigTemplateO);
    m_GConfigTemplateO = 0;
}
//===============================================
GConfigO* GConfigTemplate() {
    if(m_GConfigTemplateO == 0) {
        m_GConfigTemplateO = GConfigTemplate_New();
    }
    return m_GConfigTemplateO;
}
//===============================================
static void GConfigTemplate_Clear() {
    GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
    GMapO(GConfigTemplate, GCHAR_PTR, GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
    lDataMap->Clear(lDataMap);
}
//===============================================
static void GConfigTemplate_Remove(char* key) {
    GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
    GMapO(GConfigTemplate, GCHAR_PTR, GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
    lDataMap->Remove(lDataMap, key, GConfigTemplate_MapEqual);
}
//===============================================
static void GConfigTemplate_SetData(char* key, char* value) {
    GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
    GMapO(GConfigTemplate, GCHAR_PTR, GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
    lDataMap->SetData(lDataMap, key, value, GConfigTemplate_MapEqual);
}
//===============================================
static char* GConfigTemplate_GetData(char* key) {
    GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
    GMapO(GConfigTemplate, GCHAR_PTR, GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
    char* lValue = lDataMap->GetData(lDataMap, key, GConfigTemplate_MapEqual);
    //if(lValue == 0) {GConsole()->Print("[ GConfig ] Error GConfigTemplate_GetData: %s\n", key); exit(0);}
    return lValue;
}
//===============================================
static int GConfigTemplate_Size() {
    GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
    GMapO(GConfigTemplate, GCHAR_PTR, GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
    return lDataMap->Size(lDataMap);
}
//===============================================
static void GConfigTemplate_Show() {
    GConfigTemplateO* lConfigTemplate = m_GConfigTemplateO->m_child;
    GMapO(GConfigTemplate, GCHAR_PTR, GCHAR_PTR)* lDataMap = lConfigTemplate->m_dataMap;
    lDataMap->Show(lDataMap, GConfigTemplate_MapShow);
}
//===============================================
static int GConfigTemplate_MapEqual(char* key1, char* key2) {
    int lStrcmp = strcmp(key1, key2);
    if(lStrcmp == 0) return TRUE;
    return FALSE;
}
//===============================================
static void GConfigTemplate_MapShow(char* key, char* value) {
    printf("%s = %s\n", key, value);
}
//===============================================
