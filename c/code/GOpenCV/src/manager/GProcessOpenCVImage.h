//===============================================
#ifndef _GProcessOpenCVImage_
#define _GProcessOpenCVImage_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenCVImageO GProcessOpenCVImageO;
//===============================================
struct _GProcessOpenCVImageO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenCVImage_New();
void GProcessOpenCVImage_Delete();
GProcessO* GProcessOpenCVImage();
//===============================================
#endif
//===============================================
