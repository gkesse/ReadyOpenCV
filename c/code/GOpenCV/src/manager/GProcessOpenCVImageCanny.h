//===============================================
#ifndef _GProcessOpenCVImageCanny_
#define _GProcessOpenCVImageCanny_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenCVImageCannyO GProcessOpenCVImageCannyO;
//===============================================
struct _GProcessOpenCVImageCannyO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenCVImageCanny_New();
void GProcessOpenCVImageCanny_Delete();
GProcessO* GProcessOpenCVImageCanny();
//===============================================
#endif
//===============================================
