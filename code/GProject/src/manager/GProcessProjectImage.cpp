//===============================================
#include "GProcessProjectImage.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessProjectImage* GProcessProjectImage::m_instance = 0;
//===============================================
GProcessProjectImage::GProcessProjectImage() {

}
//===============================================
GProcessProjectImage::~GProcessProjectImage() {

}
//===============================================
GProcessProjectImage* GProcessProjectImage::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessProjectImage;
	}
	return m_instance;
}
//===============================================
void GProcessProjectImage::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();

}
//===============================================
