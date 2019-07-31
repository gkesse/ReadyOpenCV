//===============================================
#include "GProcessImageSumPlane.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessImageSumPlane* GProcessImageSumPlane::m_instance = 0;
//===============================================
GProcessImageSumPlane::GProcessImageSumPlane() {

}
//===============================================
GProcessImageSumPlane::~GProcessImageSumPlane() {

}
//===============================================
GProcessImageSumPlane* GProcessImageSumPlane::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessImageSumPlane;
	}
	return m_instance;
}
//===============================================
void GProcessImageSumPlane::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
