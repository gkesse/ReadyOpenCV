//===============================================
#ifndef _GProcessOpenCVImageGray_
#define _GProcessOpenCVImageGray_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenCVImageGrayO GProcessOpenCVImageGrayO;
//===============================================
struct _GProcessOpenCVImageGrayO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenCVImageGray_New();
void GProcessOpenCVImageGray_Delete();
GProcessO* GProcessOpenCVImageGray();
//===============================================
#endif
//===============================================
