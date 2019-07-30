//================================================
#include "GDelay.h"
//================================================
GDelay* GDelay::m_instance = 0;
//================================================
GDelay::GDelay() {

}
//================================================
GDelay::~GDelay() {

}
//================================================
GDelay* GDelay::Instance() {
	if(m_instance == 0) {
		m_instance = new GDelay;
	}
	return m_instance;
}
//================================================
int GDelay::waitKey(const int& delay) {
	int lKey = cv::waitKey(delay);
	return lKey;
}
//================================================
