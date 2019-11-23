//===============================================
#include "GImage.h"
#include "GConsole.h"
//===============================================
GDECLARE_MAP(GImage, GCHAR_PTR, GVOID_PTR)
GDEFINE_MAP(GImage, GCHAR_PTR, GVOID_PTR)
//===============================================
static GImageO* m_GImageO = 0;
//===============================================
static void GImage_Load(char* imgName, char* imgFile, int color);
static void GImage_Show(char* imgName, char* windowName);
static void GImage_Remove(char* imgName);
//===============================================
#if defined(G_USE_OPENCV_ON)
static int GImage_MapEqual(char* key1, char* key2);
#endif
//===============================================
GImageO* GImage_New() {
	GImageO* lObj = (GImageO*)malloc(sizeof(GImageO));

	lObj->m_imgMap = GMap_New_GImage_GCHAR_PTR_GVOID_PTR();

	lObj->Delete = GImage_Delete;
	lObj->Load = GImage_Load;
	lObj->Show = GImage_Show;
	lObj->Remove = GImage_Remove;
	return lObj;
}
//===============================================
void GImage_Delete() {
	GImageO* lObj = GImage();
	if(lObj != 0) {
		free(lObj);
	}
	m_GImageO = 0;
}
//===============================================
GImageO* GImage() {
	if(m_GImageO == 0) {
		m_GImageO = GImage_New();
	}
	return m_GImageO;
}
//===============================================
static void GImage_Load(char* imgName, char* imgFile, int color) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = cvLoadImage(imgFile, color);
	if(lImgMap == 0) {printf("[ GImage ] Error GImage_LoadImage: %s\n", imgFile); exit(0);}
	lImgMap->SetData(lImgMap, imgName, lImg, GImage_MapEqual);
#endif
}
//===============================================
static void GImage_Show(char* imgName, char* windowName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = (IplImage*)lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	cvShowImage(windowName, lImg);
#endif
}
//===============================================
static void GImage_Remove(char* imgName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = (IplImage*)lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	cvReleaseImage(&lImg);
#endif
}
//===============================================
#if defined(G_USE_OPENCV_ON)
static int GImage_MapEqual(char* key1, char* key2) {
	int lStrcmp = strcmp(key1, key2);
	if(lStrcmp == 0) return TRUE;
	return FALSE;
}
#endif
//===============================================
