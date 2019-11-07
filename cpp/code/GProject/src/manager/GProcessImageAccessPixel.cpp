//===============================================
#include "GProcessImageAccessPixel.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessImageAccessPixel* GProcessImageAccessPixel::m_instance = 0;
//===============================================
GProcessImageAccessPixel::GProcessImageAccessPixel() {

}
//===============================================
GProcessImageAccessPixel::~GProcessImageAccessPixel() {

}
//===============================================
GProcessImageAccessPixel* GProcessImageAccessPixel::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessImageAccessPixel;
	}
	return m_instance;
}
//===============================================
void GProcessImageAccessPixel::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
