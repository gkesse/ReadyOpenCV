//================================================
#include "GWindow.h"
//================================================
GWindow* GWindow::m_instance = 0;
//================================================
GWindow::GWindow() {

}
//================================================
GWindow::~GWindow() {

}
//================================================
GWindow* GWindow::Instance() {
	if(m_instance == 0) {
		m_instance = new GWindow;
	}
	return m_instance;
}
//================================================
void GWindow::show(const string& windowName, const int& flags) {
	cv::namedWindow(windowName, flags);
}
//================================================
void GWindow::destroy(const string& windowName) {
	cv::destroyWindow(windowName);
}
//================================================
void GWindow::destroyAll() {
	cv::destroyAllWindows();
}
//================================================
