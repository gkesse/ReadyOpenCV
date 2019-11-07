//================================================
#include "GVideo.h"
#include "GImage.h"
//================================================
GVideo* GVideo::m_instance = 0;
//================================================
GVideo::GVideo() {

}
//================================================
GVideo::~GVideo() {

}
//================================================
GVideo* GVideo::Instance() {
	if(m_instance == 0) {
		m_instance = new GVideo;
	}
	return m_instance;
}
//================================================
void GVideo::open(const string& videoName, const string& file) {
	cv::VideoCapture lCap;
	lCap.open(file);
	bool lOpen = lCap.isOpened();
	if(lOpen == false) {cout << "[ GVideo ] Error GVideo::open\n"; exit(0);}
	m_videoMap[videoName] = lCap;
}
//================================================
void GVideo::setImage(const string& videoName, const string& imageName) {
	cv::VideoCapture lCap = m_videoMap[videoName];
	cv::Mat lFrame;
	lCap >> lFrame;
	GImage::Instance()->setImage(imageName, lFrame);
}
//================================================
