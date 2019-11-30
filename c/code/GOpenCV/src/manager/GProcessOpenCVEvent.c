//===============================================
#include "GProcessOpenCVEvent.h"
#include "GOpenCVEvent.h"
//===============================================
static GProcessO* m_GProcessOpenCVEventO = 0;
//===============================================
static void GProcessOpenCVEvent_Run(int argc, char** argv);
//===============================================
GProcessO* GProcessOpenCVEvent_New() {
	GProcessO* lParent = GProcess_New();
	GProcessOpenCVEventO* lChild = (GProcessOpenCVEventO*)malloc(sizeof(GProcessOpenCVEventO));

	lChild->m_parent = lParent;

	lParent->m_child = lChild;
	lParent->Delete = GProcessOpenCVEvent_Delete;
	lParent->Run = GProcessOpenCVEvent_Run;
	return lParent;
}
//===============================================
void GProcessOpenCVEvent_Delete() {
	GProcess_Delete(m_GProcessOpenCVEventO);
	m_GProcessOpenCVEventO = 0;
}
//===============================================
GProcessO* GProcessOpenCVEvent() {
	if(m_GProcessOpenCVEventO == 0) {
		m_GProcessOpenCVEventO = GProcessOpenCVEvent_New();
	}
	return m_GProcessOpenCVEventO;
}
//===============================================
static void GProcessOpenCVEvent_Run(int argc, char** argv) {
	GOpenCVEvent()->Run();
}
//===============================================
