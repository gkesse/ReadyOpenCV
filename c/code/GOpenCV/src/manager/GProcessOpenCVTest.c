//===============================================
#include "GProcessOpenCVTest.h"
#include "GOpenCVTest.h"
//===============================================
static GProcessO* m_GProcessOpenCVTestO = 0;
//===============================================
static void GProcessOpenCVTest_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenCVTest_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenCVTestO* lChild = (GProcessOpenCVTestO*)malloc(sizeof(GProcessOpenCVTestO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenCVTest_Delete;
	lParent->Run = GProcessOpenCVTest_Run;
	return lParent;
}
//===============================================
void GProcessOpenCVTest_Delete() {
	GProcess_Delete(m_GProcessOpenCVTestO);
	m_GProcessOpenCVTestO = 0;
}
//===============================================
GProcessO* GProcessOpenCVTest() {
	if(m_GProcessOpenCVTestO == 0) {
		m_GProcessOpenCVTestO = GProcessOpenCVTest_New();
	}
	return m_GProcessOpenCVTestO;
}
//===============================================
static void GProcessOpenCVTest_Run(int argc, char** argv) {
	GOpenCVTest()->Run();
}
//===============================================
