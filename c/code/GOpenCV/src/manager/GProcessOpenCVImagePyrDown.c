//===============================================
#include "GProcessOpenCVImagePyrDown.h"
#include "GImage.h"
#include "GWindow.h"
#include "GWaitKey.h"
//===============================================
static GProcessO* m_GProcessOpenCVImagePyrDownO = 0;
//===============================================
static void GProcessOpenCVImagePyrDown_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenCVImagePyrDown_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenCVImagePyrDownO* lChild = (GProcessOpenCVImagePyrDownO*)malloc(sizeof(GProcessOpenCVImagePyrDownO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenCVImagePyrDown_Delete;
	lParent->Run = GProcessOpenCVImagePyrDown_Run;
	return lParent;
}
//===============================================
void GProcessOpenCVImagePyrDown_Delete() {
	GProcess_Delete(m_GProcessOpenCVImagePyrDownO);
	m_GProcessOpenCVImagePyrDownO = 0;
}
//===============================================
GProcessO* GProcessOpenCVImagePyrDown() {
	if(m_GProcessOpenCVImagePyrDownO == 0) {
		m_GProcessOpenCVImagePyrDownO = GProcessOpenCVImagePyrDown_New();
	}
	return m_GProcessOpenCVImagePyrDownO;
}
//===============================================
static void GProcessOpenCVImagePyrDown_Run(int argc, char** argv) {
	GImage()->Load("IMAGE", "./data/img/fruits.jpg", CV_LOAD_IMAGE_COLOR);
	GImage()->CreateHalf("IMAGE", "PYRDOWN");
	GImage()->PyrDown("IMAGE", "PYRDOWN");
	GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
	GWindow()->Create("PYRDOWN", CV_WINDOW_AUTOSIZE);
	GImage()->Show("IMAGE", "IMAGE");
	GImage()->Show("PYRDOWN", "PYRDOWN");
	GWaitKey()->Loop();
	GImage()->Remove("IMAGE");
	GImage()->Remove("PYRDOWN");
	GWindow()->RemoveAll();
}
//===============================================
