//===============================================
#include "GProcessImageCombineOperator.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessImageCombineOperator* GProcessImageCombineOperator::m_instance = 0;
//===============================================
GProcessImageCombineOperator::GProcessImageCombineOperator() {

}
//===============================================
GProcessImageCombineOperator::~GProcessImageCombineOperator() {

}
//===============================================
GProcessImageCombineOperator* GProcessImageCombineOperator::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessImageCombineOperator;
	}
	return m_instance;
}
//===============================================
void GProcessImageCombineOperator::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
