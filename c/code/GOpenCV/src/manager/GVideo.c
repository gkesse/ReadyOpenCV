//===============================================
#include "GVideo.h"
#include "GImage.h"
//===============================================
GDECLARE_MAP(GVideo, GCHAR_PTR, GVOID_PTR)
GDEFINE_MAP(GVideo, GCHAR_PTR, GVOID_PTR)
//===============================================
static GVideoO* m_GVideoO = 0;
//===============================================
static void GVideo_LoadVideo(char* capName, char* capFile);
static void GVideo_GetImageVideo(char* capName, char* imgName);
static void GVideo_RemoveVideo(char* capName);
//===============================================
#if defined(G_USE_OPENCV_ON)
static int GVideo_MapEqual(char* key1, char* key2);
#endif
//===============================================
GVideoO* GVideo_New() {
	GVideoO* lObj = (GVideoO*)malloc(sizeof(GVideoO));

	lObj->m_capMap = GMap_New_GVideo_GCHAR_PTR_GVOID_PTR();

	lObj->Delete = GVideo_Delete;
	lObj->LoadVideo = GVideo_LoadVideo;
	lObj->GetImageVideo = GVideo_GetImageVideo;
	lObj->RemoveVideo = GVideo_RemoveVideo;
	return lObj;
}
//===============================================
void GVideo_Delete() {
	GVideoO* lObj = GVideo();
	if(lObj != 0) {
		free(lObj);
	}
	m_GVideoO = 0;
}
//===============================================
GVideoO* GVideo() {
	if(m_GVideoO == 0) {
		m_GVideoO = GVideo_New();
	}
	return m_GVideoO;
}
//===============================================
static void GVideo_LoadVideo(char* capName, char* capFile) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GVideo, GCHAR_PTR, GVOID_PTR)* lCapMap = m_GVideoO->m_capMap;
    CvCapture* lCap = cvCreateFileCapture(capFile);
    if(lCap == 0) {printf("[ GVideo ] Error GVideo_CreateFile: %s\n", capFile); exit(0);}
	lCapMap->SetData(lCapMap, capName, lCap, GVideo_MapEqual);
#endif
}
//===============================================
static void GVideo_GetImageVideo(char* capName, char* imgName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GVideo, GCHAR_PTR, GVOID_PTR)* lCapMap = m_GVideoO->m_capMap;
	CvCapture* lCap = lCapMap->GetData(lCapMap, capName, GVideo_MapEqual);
	IplImage* lImg = cvQueryFrame(lCap);
	GImage()->SetImage(imgName, lImg);
#endif
}
//===============================================
static void GVideo_RemoveVideo(char* capName)  {
#if defined(G_USE_OPENCV_ON)
	GMapO(GVideo, GCHAR_PTR, GVOID_PTR)* lCapMap = m_GVideoO->m_capMap;
	CvCapture* lCap = lCapMap->GetData(lCapMap, capName, GVideo_MapEqual);
	cvReleaseCapture(&lCap);
#endif
}
//===============================================
#if defined(G_USE_OPENCV_ON)
static int GVideo_MapEqual(char* key1, char* key2) {
	int lStrcmp = strcmp(key1, key2);
	if(lStrcmp == 0) return TRUE;
	return FALSE;
}
#endif
//===============================================
