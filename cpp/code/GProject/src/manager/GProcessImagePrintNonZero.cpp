//===============================================
#include "GProcessImagePrintNonZero.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessImagePrintNonZero* GProcessImagePrintNonZero::m_instance = 0;
//===============================================
GProcessImagePrintNonZero::GProcessImagePrintNonZero() {

}
//===============================================
GProcessImagePrintNonZero::~GProcessImagePrintNonZero() {

}
//===============================================
GProcessImagePrintNonZero* GProcessImagePrintNonZero::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessImagePrintNonZero;
	}
	return m_instance;
}
//===============================================
void GProcessImagePrintNonZero::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================