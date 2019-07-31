//===============================================
#include "GProcessImagePyrDown.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessImagePyrDown* GProcessImagePyrDown::m_instance = 0;
//===============================================
GProcessImagePyrDown::GProcessImagePyrDown() {

}
//===============================================
GProcessImagePyrDown::~GProcessImagePyrDown() {

}
//===============================================
GProcessImagePyrDown* GProcessImagePyrDown::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessImagePyrDown;
	}
	return m_instance;
}
//===============================================
void GProcessImagePyrDown::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
