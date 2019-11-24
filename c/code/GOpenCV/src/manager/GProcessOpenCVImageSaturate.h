//===============================================
#ifndef _GProcessOpenCVImageSaturate_
#define _GProcessOpenCVImageSaturate_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenCVImageSaturateO GProcessOpenCVImageSaturateO;
//===============================================
struct _GProcessOpenCVImageSaturateO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenCVImageSaturate_New();
void GProcessOpenCVImageSaturate_Delete();
GProcessO* GProcessOpenCVImageSaturate();
//===============================================
#endif
//===============================================
