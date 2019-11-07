//===============================================
#include "GProcessImagePrintMatrix.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessImagePrintMatrix* GProcessImagePrintMatrix::m_instance = 0;
//===============================================
GProcessImagePrintMatrix::GProcessImagePrintMatrix() {

}
//===============================================
GProcessImagePrintMatrix::~GProcessImagePrintMatrix() {

}
//===============================================
GProcessImagePrintMatrix* GProcessImagePrintMatrix::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessImagePrintMatrix;
	}
	return m_instance;
}
//===============================================
void GProcessImagePrintMatrix::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
