//===============================================
#include "GProcessOpenCVImageSaturate.h"
#include "GImage.h"
#include "GWindow.h"
#include "GWaitKey.h"
//===============================================
static GProcessO* m_GProcessOpenCVImageSaturateO = 0;
//===============================================
static void GProcessOpenCVImageSaturate_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenCVImageSaturate_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenCVImageSaturateO* lChild = (GProcessOpenCVImageSaturateO*)malloc(sizeof(GProcessOpenCVImageSaturateO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenCVImageSaturate_Delete;
	lParent->Run = GProcessOpenCVImageSaturate_Run;
	return lParent;
}
//===============================================
void GProcessOpenCVImageSaturate_Delete() {
	GProcess_Delete(m_GProcessOpenCVImageSaturateO);
	m_GProcessOpenCVImageSaturateO = 0;
}
//===============================================
GProcessO* GProcessOpenCVImageSaturate() {
	if(m_GProcessOpenCVImageSaturateO == 0) {
		m_GProcessOpenCVImageSaturateO = GProcessOpenCVImageSaturate_New();
	}
	return m_GProcessOpenCVImageSaturateO;
}
//===============================================
static void GProcessOpenCVImageSaturate_Run(int argc, char** argv) {
	sGSaturate lSaturate = (sGSaturate){
		{1, 0}, {1, 0}, {0, 255}
	};

	GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
	GImage()->CreateParams("IMAGE", "SATURATE");
	GImage()->Copy("IMAGE", "SATURATE");
	GImage()->Saturate("SATURATE", &lSaturate);
	GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
	GWindow()->Create("SATURATE", CV_WINDOW_AUTOSIZE);
	GImage()->Show("IMAGE", "IMAGE");
	GImage()->Show("SATURATE", "SATURATE");
	GWaitKey()->Loop();
	GImage()->Remove("IMAGE");
	GImage()->Remove("SMOOTH");
	GWindow()->RemoveAll();
}
//===============================================
