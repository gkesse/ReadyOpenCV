//===============================================
#include "GProcessProjectVideo.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessProjectVideo* GProcessProjectVideo::m_instance = 0;
//===============================================
GProcessProjectVideo::GProcessProjectVideo() {

}
//===============================================
GProcessProjectVideo::~GProcessProjectVideo() {

}
//===============================================
GProcessProjectVideo* GProcessProjectVideo::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessProjectVideo;
	}
	return m_instance;
}
//===============================================
void GProcessProjectVideo::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();

}
//===============================================
