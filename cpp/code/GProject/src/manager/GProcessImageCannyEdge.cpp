//===============================================
#include "GProcessImageCannyEdge.h"
#include "GImage.h"
#include "GWindow.h"
#include "GDelay.h"
//===============================================
GProcessImageCannyEdge* GProcessImageCannyEdge::m_instance = 0;
//===============================================
GProcessImageCannyEdge::GProcessImageCannyEdge() {

}
//===============================================
GProcessImageCannyEdge::~GProcessImageCannyEdge() {

}
//===============================================
GProcessImageCannyEdge* GProcessImageCannyEdge::Instance() {
	if(m_instance == 0) {
		m_instance = new GProcessImageCannyEdge;
	}
	return m_instance;
}
//===============================================
void GProcessImageCannyEdge::run(int argc, char **argv) {
	GWindow::Instance()->show("ORIGINAL", cv::WINDOW_AUTOSIZE);
	GImage::Instance()->read("ORIGINAL", "data/img/fruits.jpg", -1);
	GImage::Instance()->show("ORIGINAL", "ORIGINAL");
	GDelay::Instance()->waitKey(0);
	GWindow::Instance()->destroyAll();
}
//===============================================
