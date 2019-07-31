//================================================
#include "GVideoWriter.h"
//================================================
GVideoWriter* GVideoWriter::m_instance = 0;
//================================================
GVideoWriter::GVideoWriter() {

}
//================================================
GVideoWriter::~GVideoWriter() {

}
//================================================
GVideoWriter* GVideoWriter::Instance() {
	if(m_instance == 0) {
		m_instance = new GVideoWriter;
	}
	return m_instance;
}
//================================================
int GVideoWriter::waitKey(const int& delay) {
	int lKey = cv::waitKey(delay);
	return lKey;
}
//================================================
