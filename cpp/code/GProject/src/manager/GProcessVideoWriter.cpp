//===============================================
#include "GProcessVideoWriter.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessVideoWriter* GProcessVideoWriter::m_instance = 0;
//===============================================
GProcessVideoWriter::GProcessVideoWriter() {

}
//===============================================
GProcessVideoWriter::~GProcessVideoWriter() {

}
//===============================================
GProcessVideoWriter* GProcessVideoWriter::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessVideoWriter;
	}
	return m_instance;
}
//===============================================
void GProcessVideoWriter::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
