//================================================
#include "GImage.h"
//================================================
GImage* GImage::m_instance = 0;
//================================================
GImage::GImage() {

}
//================================================
GImage::~GImage() {
	
}
//================================================
GImage* GImage::Instance() {
	if(m_instance == 0) {
		m_instance = new GImage;
	}
	return m_instance;
}
//================================================
void GImage::read(const string& imageName, const string& file, const int& flags) {
	cv::Mat lImg = cv::imread(file, flags);
	m_imgMap[imageName] = lImg;
}
//================================================
void GImage::show(const string& imageName, const string& windowName) {
	cv::Mat lImg = m_imgMap[imageName];
	cv::imshow(windowName, lImg);
}
//================================================
void GImage::setImage(const string& imageName, const cv::Mat& image) {
	m_imgMap[imageName] = image;
}
//================================================
bool GImage::empty(const string& imageName) {
	cv::Mat lImg = m_imgMap[imageName];
	bool lEmpty = lImg.empty();
	return lEmpty;
}
//================================================
