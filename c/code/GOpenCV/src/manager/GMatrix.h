//===============================================
#ifndef _GMatrix_
#define _GMatrix_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GMatrixO GMatrixO;
typedef struct _GMapO_GMatrix_GCHAR_PTR_GVOID_PTR GMapO_GMatrix_GCHAR_PTR_GVOID_PTR;
//===============================================
struct _GMatrixO {
	void (*Delete)();
	void (*Create)(char* matName, int row, int col, int type);
	CvMat* (*Get)(char* matName);
	void (*Rotate2D)(char* matName, sGRotate2D rotate);
	void (*GetPerspective)(char* matName, sGQuad quad);
	void (*Remove)(char* matName);
	GMapO(GMatrix, GCHAR_PTR, GVOID_PTR)* m_matMap;
};
//===============================================
GMatrixO* GMatrix_New();
void GMatrix_Delete();
GMatrixO* GMatrix();
//===============================================
#endif
//===============================================
