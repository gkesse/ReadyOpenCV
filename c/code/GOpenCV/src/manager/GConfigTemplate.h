//===============================================
#ifndef _GConfigTemplate_
#define _GConfigTemplate_
//===============================================
#include "GConfig.h"
#include "GMap.h"
//===============================================
typedef struct _GConfigTemplateO GConfigTemplateO;
typedef struct _GMapO_GConfigTemplate_GCHAR_PTR_GCHAR_PTR GMapO_GConfigTemplate_GCHAR_PTR_GCHAR_PTR;
//===============================================
struct _GConfigTemplateO {
    GConfigO* m_parent;
    GMapO(GConfigTemplate, GCHAR_PTR, GCHAR_PTR)* m_dataMap;
};
//===============================================
GConfigO* GConfigTemplate_New();
void GConfigTemplate_Delete();
GConfigO* GConfigTemplate();
//===============================================
#endif
//===============================================
