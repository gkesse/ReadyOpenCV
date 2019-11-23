//===============================================
#include "GWindow.h"
//===============================================
static GWindowO* m_GWindowO = 0;
//===============================================
static void GWindow_Create(char* windowName, int flags);
static void GWindow_Remove(char* windowName);
static void GWindow_RemoveAll();
//===============================================
GWindowO* GWindow_New() {
	GWindowO* lObj = (GWindowO*)malloc(sizeof(GWindowO));
	lObj->Delete = GWindow_Delete;
	lObj->Create = GWindow_Create;
	lObj->Remove = GWindow_Remove;
	lObj->RemoveAll = GWindow_RemoveAll;
	return lObj;
}
//===============================================
void GWindow_Delete() {
	GWindowO* lObj = GWindow();
	if(lObj != 0) {
		free(lObj);
	}
	m_GWindowO = 0;
}
//===============================================
GWindowO* GWindow() {
	if(m_GWindowO == 0) {
		m_GWindowO = GWindow_New();
	}
	return m_GWindowO;
}
//===============================================
static void GWindow_Create(char* windowName, int flags) {
	cvNamedWindow(windowName, flags);
}
//===============================================
static void GWindow_Remove(char* windowName) {
	cvDestroyWindow(windowName);
}
//===============================================
static void GWindow_RemoveAll() {
	cvDestroyAllWindows();
}
//===============================================
