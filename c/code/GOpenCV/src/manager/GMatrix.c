//===============================================
#include "GMatrix.h"
//===============================================
GDECLARE_MAP(GMatrix, GCHAR_PTR, GVOID_PTR)
GDEFINE_MAP(GMatrix, GCHAR_PTR, GVOID_PTR)
//===============================================
static GMatrixO* m_GMatrixO = 0;
//===============================================
static void GMatrix_Create(char* storeName, int row, int col, int type);
static void GMatrix_Remove(char* matName);
//===============================================
#if defined(G_USE_OPENCV_ON)
static int GMatrix_MapEqual(char* key1, char* key2);
#endif
//===============================================
GMatrixO* GMatrix_New() {
	GMatrixO* lObj = (GMatrixO*)malloc(sizeof(GMatrixO));

	lObj->m_matMap = GMap_New_GMatrix_GCHAR_PTR_GVOID_PTR();

	lObj->Delete = GMatrix_Delete;
	lObj->Create = GMatrix_Create;
	lObj->Remove = GMatrix_Remove;
	return lObj;
}
//===============================================
void GMatrix_Delete() {
	GMatrixO* lObj = GMatrix();
	if(lObj != 0) {
		free(lObj);
	}
	m_GMatrixO = 0;
}
//===============================================
GMatrixO* GMatrix() {
	if(m_GMatrixO == 0) {
		m_GMatrixO = GMatrix_New();
	}
	return m_GMatrixO;
}
//===============================================
static void GMatrix_Create(char* matName, int row, int col, int type) {
#ifdef G_USE_OPENCV_ON
	GMapO(GMatrix, GCHAR_PTR, GVOID_PTR)* lMatMap = m_GMatrixO->m_matMap;
	CvMat* lMat = cvCreateMat(row, col, type);
	if(lMat == 0) {printf("[ GMatrix ] Error GMatrix_Create\n"); exit(0);}
	lMatMap->SetData(lMatMap, matName, lMat, GMatrix_MapEqual);
#endif
}
//===============================================
static void GMatrix_Remove(char* matName) {
#ifdef G_USE_OPENCV_ON
	GMapO(GMatrix, GCHAR_PTR, GVOID_PTR)* lMatMap = m_GMatrixO->m_matMap;
	CvMat* lMat = lMatMap->GetData(lMatMap, matName, GMatrix_MapEqual);
	cvReleaseMat(&lMat);
#endif
}
//===============================================
#if defined(G_USE_OPENCV_ON)
static int GMatrix_MapEqual(char* key1, char* key2) {
	int lStrcmp = strcmp(key1, key2);
	if(lStrcmp == 0) return TRUE;
	return FALSE;
}
#endif
//===============================================
