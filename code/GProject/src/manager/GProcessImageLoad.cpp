//===============================================
#include "GProcessImageLoad.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessImageLoad* GProcessImageLoad::m_instance = 0;
//===============================================
GProcessImageLoad::GProcessImageLoad() {

}
//===============================================
GProcessImageLoad::~GProcessImageLoad() {

}
//===============================================
GProcessImageLoad* GProcessImageLoad::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessImageLoad;
	}
	return m_instance;
}
//===============================================
void GProcessImageLoad::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
