//===============================================
#include "GProcessTest.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessTest* GProcessTest::m_instance = 0;
//===============================================
GProcessTest::GProcessTest() {

}
//===============================================
GProcessTest::~GProcessTest() {

}
//===============================================
GProcessTest* GProcessTest::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessTest;
	}
	return m_instance;
}
//===============================================
void GProcessTest::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();

}
//===============================================
