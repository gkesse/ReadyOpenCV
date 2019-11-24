//===============================================
#include "GTest.h"
#include "GImage.h"
#include "GWindow.h"
#include "GWaitKey.h"
//===============================================
static GTestO* m_GTestO = 0;
//===============================================
static void GTest_Run();
static void GTest_ImageLoad();
//===============================================
GTestO* GTest_New() {
	GTestO* lObj = (GTestO*)malloc(sizeof(GTestO));
	lObj->Delete = GTest_Delete;
	lObj->Run = GTest_Run;
	return lObj;
}
//===============================================
void GTest_Delete() {
	GTestO* lObj = GTest();
	if(lObj != 0) {
		free(lObj);
	}
	m_GTestO = 0;
}
//===============================================
GTestO* GTest() {
	if(m_GTestO == 0) {
		m_GTestO = GTest_New();
	}
	return m_GTestO;
}
//===============================================
static void GTest_Run() {
	printf("__FUNCTION__ : %s\n", __FUNCTION__);
}
//===============================================
static void GTest_ImageLoad() {
	GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
	GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
	GImage()->Show("IMAGE", "IMAGE");
	GWaitKey()->Loop();
	GImage()->Remove("IMAGE");
	GWindow()->RemoveAll();
}
//===============================================
