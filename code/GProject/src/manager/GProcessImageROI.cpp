//===============================================
#include "GProcessImageROI.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessImageROI* GProcessImageROI::m_instance = 0;
//===============================================
GProcessImageROI::GProcessImageROI() {

}
//===============================================
GProcessImageROI::~GProcessImageROI() {

}
//===============================================
GProcessImageROI* GProcessImageROI::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessImageROI;
	}
	return m_instance;
}
//===============================================
void GProcessImageROI::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
