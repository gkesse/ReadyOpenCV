//===============================================
#include "GProcessVideoCamera.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessVideoCamera* GProcessVideoCamera::m_instance = 0;
//===============================================
GProcessVideoCamera::GProcessVideoCamera() {

}
//===============================================
GProcessVideoCamera::~GProcessVideoCamera() {

}
//===============================================
GProcessVideoCamera* GProcessVideoCamera::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessVideoCamera;
	}
	return m_instance;
}
//===============================================
void GProcessVideoCamera::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
