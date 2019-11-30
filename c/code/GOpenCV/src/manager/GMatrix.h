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
	void (*Create)(char* storeName, int row, int col, int type);
	void (*Remove)(char* storeName);
	GMapO(GMatrix, GCHAR_PTR, GVOID_PTR)* m_matMap;
};
//===============================================
GMatrixO* GMatrix_New();
void GMatrix_Delete();
GMatrixO* GMatrix();
//===============================================
#endif
//===============================================
