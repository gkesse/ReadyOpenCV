//===============================================
#ifndef _GOpenCVImage_
#define _GOpenCVImage_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GOpenCVImageO GOpenCVImageO;
//===============================================
struct _GOpenCVImageO {
    void (*Delete)();
    void (*Run)();
    int m_continue;
};
//===============================================
GOpenCVImageO* GOpenCVImage_New();
void GOpenCVImage_Delete();
GOpenCVImageO* GOpenCVImage();
//===============================================
#endif
//===============================================
