//===============================================
#ifndef _GProcessHelp_
#define _GProcessHelp_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessHelpO GProcessHelpO;
//===============================================
struct _GProcessHelpO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessHelp_New();
void GProcessHelp_Delete();
GProcessO* GProcessHelp();
//===============================================
#endif
//===============================================
