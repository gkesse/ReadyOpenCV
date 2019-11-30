//===============================================
#include "GProcessOpenCVImage.h"
#include "GOpenCVImage.h"
//===============================================
static GProcessO* m_GProcessOpenCVImageO = 0;
//===============================================
static void GProcessOpenCVImage_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenCVImage_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenCVImageO* lChild = (GProcessOpenCVImageO*)malloc(sizeof(GProcessOpenCVImageO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenCVImage_Delete;
	lParent->Run = GProcessOpenCVImage_Run;
	return lParent;
}
//===============================================
void GProcessOpenCVImage_Delete() {
	GProcess_Delete(m_GProcessOpenCVImageO);
	m_GProcessOpenCVImageO = 0;
}
//===============================================
GProcessO* GProcessOpenCVImage() {
	if(m_GProcessOpenCVImageO == 0) {
		m_GProcessOpenCVImageO = GProcessOpenCVImage_New();
	}
	return m_GProcessOpenCVImageO;
}
//===============================================
static void GProcessOpenCVImage_Run(int argc, char** argv) {
	GOpenCVImage()->Run();
}
//===============================================
