//===============================================
#include "GProcess.h"
#include "GProcessHelp.h"
#include "GProcessOpenCVTest.h"
#include "GProcessOpenCVImageLoad.h"
#include "GProcessOpenCVImageSmooth.h"
#include "GProcessOpenCVImagePyrDown.h"
#include "GProcessOpenCVImageGray.h"
#include "GProcessOpenCVImageCanny.h"
#include "GProcessOpenCVImageSaturate.h"
#include "GString2.h"
#include "GConfig.h"
//===============================================
GProcessO* GProcess_New() {
	GProcessO* lObj = (GProcessO*)malloc(sizeof(GProcessO));
	lObj->m_child = 0;
	return lObj;
}
//===============================================
void GProcess_Delete(GProcessO* obj) {
	if(obj != 0) {
		if(obj->m_child != 0) {
			free(obj->m_child);
		}
		free(obj);
	}
}
//===============================================
GProcessO* GProcess() {
	char* lKey = GConfig()->GetData("PROCESS");
	if(GString2()->IsEqual(lKey, "HELP")) return GProcessHelp();
	if(GString2()->IsEqual(lKey, "OPENCV_TEST")) return GProcessOpenCVTest();
	if(GString2()->IsEqual(lKey, "OPENCV_IMAGE_LOAD")) return GProcessOpenCVImageLoad();
	if(GString2()->IsEqual(lKey, "OPENCV_IMAGE_SMOOTH")) return GProcessOpenCVImageSmooth();
	if(GString2()->IsEqual(lKey, "OPENCV_IMAGE_PYRDOWN")) return GProcessOpenCVImagePyrDown();
	if(GString2()->IsEqual(lKey, "OPENCV_IMAGE_GRAY")) return GProcessOpenCVImageGray();
	if(GString2()->IsEqual(lKey, "OPENCV_IMAGE_CANNY")) return GProcessOpenCVImageCanny();
	if(GString2()->IsEqual(lKey, "OPENCV_IMAGE_SATURATE")) return GProcessOpenCVImageSaturate();
	return GProcessHelp();
}
//===============================================
