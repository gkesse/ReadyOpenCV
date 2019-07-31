//================================================
#include "GTrackbar.h"
//================================================
GTrackbar* GTrackbar::m_instance = 0;
//================================================
GTrackbar::GTrackbar() {

}
//================================================
GTrackbar::~GTrackbar() {

}
//================================================
GTrackbar* GTrackbar::Instance() {
	if(m_instance == 0) {
		m_instance = new GTrackbar;
	}
	return m_instance;
}
//================================================
int GTrackbar::waitKey(const int& delay) {
	int lKey = cv::waitKey(delay);
	return lKey;
}
//================================================
