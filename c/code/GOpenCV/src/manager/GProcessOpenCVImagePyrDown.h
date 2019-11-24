//===============================================
#ifndef _GProcessOpenCVImagePyrDown_
#define _GProcessOpenCVImagePyrDown_
//===============================================
#include "GProcess.h"
//===============================================
typedef struct _GProcessOpenCVImagePyrDownO GProcessOpenCVImagePyrDownO;
//===============================================
struct _GProcessOpenCVImagePyrDownO {
    GProcessO* m_parent;
};
//===============================================
GProcessO* GProcessOpenCVImagePyrDown_New();
void GProcessOpenCVImagePyrDown_Delete();
GProcessO* GProcessOpenCVImagePyrDown();
//===============================================
#endif
//===============================================
