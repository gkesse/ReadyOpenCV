//===============================================
#ifndef _GOptions_
#define _GOptions_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GOptionsO GOptionsO;
//===============================================
struct _GOptionsO {
    void (*Delete)();
    void (*GetArgs)(int argc, char** argv);
};
//===============================================
GOptionsO* GOptions_New();
void GOptions_Delete();
GOptionsO* GOptions();
//===============================================
#endif
//===============================================
