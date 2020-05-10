//===============================================
#include "GOpenCV.h"
#include "GTesseract.h"
#include "GDebug.h"
//================================================
#if defined(_GUSE_OPENCV_ON_)
//===============================================
GOpenCV* GOpenCV::m_instance = 0;
//===============================================
GOpenCV::GOpenCV() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GOpenCV::~GOpenCV() {

}
//===============================================
GOpenCV* GOpenCV::Instance() {
    if(m_instance == 0) {
        m_instance = new GOpenCV;
    }
    return m_instance;
}
//===============================================
void GOpenCV::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/fruits.jpg");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    GOpenCV::Instance()->createWindow("org");
    GOpenCV::Instance()->showImage("org", "org");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->deleteImage("org");   
    GOpenCV::Instance()->destroyWindows();   
}
//===============================================
// image
//===============================================
void GOpenCV::loadImage(std::string imgId, std::string filename) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = new cv::Mat;
    *lImg = cv::imread(filename, -1);
    m_imgMap[imgId] = lImg;
}
//===============================================
void GOpenCV::createImage(std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = new cv::Mat;
    m_imgMap[imgId] = lImg;
}
//=============================================== 
cv::Mat* GOpenCV::getImage(std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    return m_imgMap[imgId];
}
//===============================================
bool GOpenCV::checkEmptyImage(std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    bool lEmpty = lImg->empty();
    return lEmpty;
}
//===============================================
void GOpenCV::showImage(std::string imgId, std::string windowId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    imshow(windowId, *lImg);
}
//===============================================
void GOpenCV::cannyImage(std::string imgId, std::string outId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::Canny(*lImg, *lOut, 10, 100, 3, true);
}
//===============================================
void GOpenCV::gaussianBlurImage(std::string imgId, std::string outId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::GaussianBlur(*lImg, *lOut, cv::Size(5,5), 3, 3);
}
//===============================================
void GOpenCV::pyrDownImage(std::string imgId, std::string outId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::pyrDown(*lImg, *lOut);
}
//===============================================
void GOpenCV::logPolarImage(std::string imgId, std::string outId, int x, int y) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::logPolar(*lImg, *lOut, cv::Point2f(x, y), 40, cv::WARP_FILL_OUTLIERS);
}
//===============================================
void GOpenCV::convertImage(std::string imgId, std::string outId, int convertId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::cvtColor(*lImg, *lOut, convertId);
}
//===============================================
void GOpenCV::getPixelImage(std::string imgId, int x, int y, int& red, int& green, int& blue) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Vec3b lColor = lImg->at<cv::Vec3b>(y, x);
    red = lColor[2];
    green = lColor[1];
    blue = lColor[0];
}
//===============================================
void GOpenCV::getPixelImage(std::string imgId, int x, int y, int& color) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    color = lImg->at<uchar>(y, x);
}
//===============================================
void GOpenCV::setPixelImage(std::string imgId, int x, int y, int red, int green, int blue) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Vec3b lColor;
    lColor[2] = red;
    lColor[1] = green;
    lColor[0] = blue;
    lImg->at<cv::Vec3b>(y, x) = lColor;
}
//===============================================
void GOpenCV::setPixelImage(std::string imgId, int x, int y, int color) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    lImg->at<cv::Vec3b>(y, x) = color;
}
//===============================================
std::string GOpenCV::getStringImage(std::string imgId, std::string language) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GTesseract::Instance()->createTesseract(imgId, language);
    GTesseract::Instance()->setImageOpenCV(imgId, imgId);
    std::string lString = GTesseract::Instance()->getString(imgId);
    GTesseract::Instance()->deleteTesseract(imgId);
    return lString;
}
//===============================================
void GOpenCV::deleteImage(std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    if(lImg != 0) lImg->release();
    delete lImg;
    m_imgMap[imgId] = 0;
}
//===============================================
// video
//===============================================
void GOpenCV::openVideo(std::string videoId, std::string filename) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::VideoCapture* lCap = new cv::VideoCapture;
    lCap->open(filename);
    m_videoMap[videoId] = lCap;
}
//===============================================
bool GOpenCV::checkOpenVideo(std::string videoId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::VideoCapture* lCap = m_videoMap[videoId];
    bool lOpen = lCap->isOpened();
    return lOpen;
}
//===============================================
void GOpenCV::getImageVideo(std::string videoId, std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::VideoCapture* lCap = m_videoMap[videoId];
    cv::Mat* lImg = m_imgMap[imgId];
    *lCap >> *lImg;
}
//===============================================
void GOpenCV::setPropertyVideo(std::string videoId, int propId, double value) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::VideoCapture* lCap = m_videoMap[videoId];
    lCap->set(propId, value);
}
//===============================================
double GOpenCV::getPropertyVideo(std::string videoId, int propId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::VideoCapture* lCap = m_videoMap[videoId];
    double lValue = lCap->get(propId);
    return lValue;
}
//===============================================
void GOpenCV::deleteVideo(std::string videoId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::VideoCapture* lCap = m_videoMap[videoId];
    if(lCap != 0) lCap->release();
    delete lCap;
    m_videoMap[videoId] = 0;
}
//===============================================
// video_writer
//===============================================
void GOpenCV::openVideoWriter(std::string videoWriterId, std::string filename, int fourcc, double fps, int width, int height) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::VideoWriter* lVideoWriter = new cv::VideoWriter;
    lVideoWriter->open(filename, fourcc, fps, cv::Size(width, height));
    m_videoWriterMap[videoWriterId] = lVideoWriter;
}
//===============================================
void GOpenCV::writeImageVideoWriter(std::string videoWriterId, std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::VideoWriter* lVideoWriter = m_videoWriterMap[videoWriterId];
    cv::Mat* lImg = m_imgMap[imgId];
    *lVideoWriter << *lImg;
}
//===============================================
void GOpenCV::deleteVideoWriter(std::string videoWriterId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::VideoWriter* lVideoWriter = m_videoWriterMap[videoWriterId];
    if(lVideoWriter != 0) lVideoWriter->release();
    delete lVideoWriter;
    m_videoWriterMap[videoWriterId] = 0;
}
//===============================================
// key
//===============================================
int GOpenCV::waitKey(int delay) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    int lKey = cv::waitKey(delay);
    return lKey;
}
//===============================================
void GOpenCV::createWindow(std::string windowId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::namedWindow(windowId, cv::WINDOW_AUTOSIZE );
}
//===============================================
// window
//===============================================
void GOpenCV::destroyWindows() {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::destroyAllWindows();
}
//===============================================
#endif
//===============================================
