//===============================================
#include "GProcessOpenCVImageGray.h"
#include "GImage.h"
#include "GWindow.h"
#include "GWaitKey.h"
//===============================================
static GProcessO* m_GProcessOpenCVImageGrayO = 0;
//===============================================
static void GProcessOpenCVImageGray_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenCVImageGray_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenCVImageGrayO* lChild = (GProcessOpenCVImageGrayO*)malloc(sizeof(GProcessOpenCVImageGrayO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenCVImageGray_Delete;
	lParent->Run = GProcessOpenCVImageGray_Run;
	return lParent;
}
//===============================================
void GProcessOpenCVImageGray_Delete() {
	GProcess_Delete(m_GProcessOpenCVImageGrayO);
	m_GProcessOpenCVImageGrayO = 0;
}
//===============================================
GProcessO* GProcessOpenCVImageGray() {
	if(m_GProcessOpenCVImageGrayO == 0) {
		m_GProcessOpenCVImageGrayO = GProcessOpenCVImageGray_New();
	}
	return m_GProcessOpenCVImageGrayO;
}
//===============================================
static void GProcessOpenCVImageGray_Run(int argc, char** argv) {
	GImage()->Load("IMAGE", "./data/img/fruits.jpg", CV_LOAD_IMAGE_COLOR);
	GImage()->CreateGray("IMAGE", "GRAY");
	GImage()->Gray("IMAGE", "GRAY");
	GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
	GWindow()->Create("GRAY", CV_WINDOW_AUTOSIZE);
	GImage()->Show("IMAGE", "IMAGE");
	GImage()->Show("GRAY", "GRAY");
	GWaitKey()->Loop();
	GImage()->Remove("IMAGE");
	GImage()->Remove("GRAY");
	GWindow()->RemoveAll();
}
//===============================================
