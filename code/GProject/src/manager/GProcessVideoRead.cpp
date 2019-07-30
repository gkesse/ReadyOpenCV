//===============================================
#include "GProcessVideoRead.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
#include "GVideo.h"
//===============================================
GProcessVideoRead* GProcessVideoRead::m_instance = 0;
//===============================================
GProcessVideoRead::GProcessVideoRead() {

}
//===============================================
GProcessVideoRead::~GProcessVideoRead() {

}
//===============================================
GProcessVideoRead* GProcessVideoRead::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessVideoRead;
	}
	return m_instance;
}
//===============================================
void GProcessVideoRead::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GVideo::Instance()->open("ORIGINAL", "data/video/test.avi");
	while(1) {
		GVideo::Instance()->setImage("ORIGINAL", "ORIGINAL");
		bool lEmpty = GImage::Instance()->empty("ORIGINAL");
		if(lEmpty == true) break;
		GImage::Instance()->show("ORIGINAL", "ORIGINAL");
		char lKey = (char)GDelay::Instance()->waitKey(33);
		if(lKey >= 0) break;
	}
	GWindow::Instance()->destroyAll();
}
//===============================================
