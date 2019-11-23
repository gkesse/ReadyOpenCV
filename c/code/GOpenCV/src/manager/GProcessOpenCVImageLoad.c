//===============================================
#include "GProcessOpenCVImageLoad.h"
#include "GImage.h"
#include "GWindow.h"
#include "GWaitKey.h"
//===============================================
static GProcessO* m_GProcessOpenCVImageLoadO = 0;
//===============================================
static void GProcessOpenCVImageLoad_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenCVImageLoad_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenCVImageLoadO* lChild = (GProcessOpenCVImageLoadO*)malloc(sizeof(GProcessOpenCVImageLoadO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenCVImageLoad_Delete;
	lParent->Run = GProcessOpenCVImageLoad_Run;
	return lParent;
}
//===============================================
void GProcessOpenCVImageLoad_Delete() {
	GProcess_Delete(m_GProcessOpenCVImageLoadO);
	m_GProcessOpenCVImageLoadO = 0;
}
//===============================================
GProcessO* GProcessOpenCVImageLoad() {
	if(m_GProcessOpenCVImageLoadO == 0) {
		m_GProcessOpenCVImageLoadO = GProcessOpenCVImageLoad_New();
	}
	return m_GProcessOpenCVImageLoadO;
}
//===============================================
static void GProcessOpenCVImageLoad_Run(int argc, char** argv) {
	GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
	GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
	GImage()->Show("IMAGE", "IMAGE");
	GWaitKey()->Loop();
	GImage()->Remove("IMAGE");
	GWindow()->RemoveAll();
}
//===============================================
