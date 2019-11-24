//===============================================
#include "GProcessOpenCVImageCanny.h"
#include "GImage.h"
#include "GWindow.h"
#include "GWaitKey.h"
//===============================================
static GProcessO* m_GProcessOpenCVImageCannyO = 0;
//===============================================
static void GProcessOpenCVImageCanny_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenCVImageCanny_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenCVImageCannyO* lChild = (GProcessOpenCVImageCannyO*)malloc(sizeof(GProcessOpenCVImageCannyO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenCVImageCanny_Delete;
	lParent->Run = GProcessOpenCVImageCanny_Run;
	return lParent;
}
//===============================================
void GProcessOpenCVImageCanny_Delete() {
	GProcess_Delete(m_GProcessOpenCVImageCannyO);
	m_GProcessOpenCVImageCannyO = 0;
}
//===============================================
GProcessO* GProcessOpenCVImageCanny() {
	if(m_GProcessOpenCVImageCannyO == 0) {
		m_GProcessOpenCVImageCannyO = GProcessOpenCVImageCanny_New();
	}
	return m_GProcessOpenCVImageCannyO;
}
//===============================================
static void GProcessOpenCVImageCanny_Run(int argc, char** argv) {
	GImage()->Load("IMAGE", "./data/img/fruits.jpg", CV_LOAD_IMAGE_COLOR);
	GImage()->CreateGray("IMAGE", "CANNY");
	GImage()->Gray("IMAGE", "CANNY");
	GImage()->Canny("CANNY", "CANNY", 10, 100, 3);
	GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
	GWindow()->Create("CANNY", CV_WINDOW_AUTOSIZE);
	GImage()->Show("IMAGE", "IMAGE");
	GImage()->Show("CANNY", "CANNY");
	GWaitKey()->Loop();
	GImage()->Remove("IMAGE");
	GImage()->Remove("CANNY");
	GWindow()->RemoveAll();
}
//===============================================
