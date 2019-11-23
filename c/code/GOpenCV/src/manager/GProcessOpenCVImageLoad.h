//===============================================
#ifndef _GProcessOpenCVImageLoad_
#define _GProcessOpenCVImageLoad_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenCVImageLoadO GProcessOpenCVImageLoadO;
//===============================================
struct _GProcessOpenCVImageLoadO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenCVImageLoad_New();
void GProcessOpenCVImageLoad_Delete();
GProcessO* GProcessOpenCVImageLoad();
//===============================================
#endif
//===============================================
