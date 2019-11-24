//===============================================
#include "GProcessOpenCVImageSmooth.h"
#include "GImage.h"
#include "GWindow.h"
#include "GWaitKey.h"
//===============================================
static GProcessO* m_GProcessOpenCVImageSmoothO = 0;
//===============================================
static void GProcessOpenCVImageSmooth_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenCVImageSmooth_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenCVImageSmoothO* lChild = (GProcessOpenCVImageSmoothO*)malloc(sizeof(GProcessOpenCVImageSmoothO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenCVImageSmooth_Delete;
	lParent->Run = GProcessOpenCVImageSmooth_Run;
	return lParent;
}
//===============================================
void GProcessOpenCVImageSmooth_Delete() {
	GProcess_Delete(m_GProcessOpenCVImageSmoothO);
	m_GProcessOpenCVImageSmoothO = 0;
}
//===============================================
GProcessO* GProcessOpenCVImageSmooth() {
	if(m_GProcessOpenCVImageSmoothO == 0) {
		m_GProcessOpenCVImageSmoothO = GProcessOpenCVImageSmooth_New();
	}
	return m_GProcessOpenCVImageSmoothO;
}
//===============================================
static void GProcessOpenCVImageSmooth_Run(int argc, char** argv) {
	GImage()->Load("IMAGE", "./data/img/fruits.jpg", CV_LOAD_IMAGE_COLOR);
	GImage()->CreateParams("IMAGE", "SMOOTH");
	GImage()->Smooth("IMAGE", "SMOOTH");
	GImage()->Smooth("SMOOTH", "SMOOTH");
	GImage()->Smooth("SMOOTH", "SMOOTH");
	GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
	GWindow()->Create("SMOOTH", CV_WINDOW_AUTOSIZE);
	GImage()->Show("IMAGE", "IMAGE");
	GImage()->Show("SMOOTH", "SMOOTH");
	GWaitKey()->Loop();
	GImage()->Remove("IMAGE");
	GImage()->Remove("SMOOTH");
	GWindow()->RemoveAll();
}
//===============================================
