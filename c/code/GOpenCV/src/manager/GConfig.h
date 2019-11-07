//===============================================
#ifndef _GConfig_
#define _GConfig_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GConfigO GConfigO;
//===============================================
struct _GConfigO {
    void* m_child;
    void (*Delete)();
    void (*Clear)();
    void (*Remove)(char* key);
    void (*SetData)(char* key, char* value);
    char* (*GetData)(char* key);
    int (*Size)();
    void (*Show)();
};
//===============================================
GConfigO* GConfig_New();
void GConfig_Delete(GConfigO* obj);
GConfigO* GConfig();
//===============================================
#endif
//===============================================
