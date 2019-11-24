//===============================================
#ifndef _GProcessOpenCVImageSmooth_
#define _GProcessOpenCVImageSmooth_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenCVImageSmoothO GProcessOpenCVImageSmoothO;
//===============================================
struct _GProcessOpenCVImageSmoothO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenCVImageSmooth_New();
void GProcessOpenCVImageSmooth_Delete();
GProcessO* GProcessOpenCVImageSmooth();
//===============================================
#endif
//===============================================
