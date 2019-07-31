//===============================================
#include "GProcessImageGaussianBlur.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessImageGaussianBlur* GProcessImageGaussianBlur::m_instance = 0;
//===============================================
GProcessImageGaussianBlur::GProcessImageGaussianBlur() {

}
//===============================================
GProcessImageGaussianBlur::~GProcessImageGaussianBlur() {

}
//===============================================
GProcessImageGaussianBlur* GProcessImageGaussianBlur::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessImageGaussianBlur;
	}
	return m_instance;
}
//===============================================
void GProcessImageGaussianBlur::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
