//===============================================
#include "GZbar.h"
#include "GOpenCV.h"
#include "GDebug.h"
//================================================
#if defined(_GUSE_ZBAR_ON_)
//===============================================
GZbar* GZbar::m_instance = 0;
//===============================================
GZbar::GZbar() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GZbar::~GZbar() {

}
//===============================================
GZbar* GZbar::Instance() {
    if(m_instance == 0) {
        m_instance = new GZbar;
    }
    return m_instance;
}
//===============================================
void GZbar::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
// Image
//===============================================
void GZbar::createImage(std::string imageId, std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = GOpenCV::Instance()->getImage(imgId);
    zbar::Image* lImage = new zbar::Image(lImg->cols, lImg->rows, "Y800", lImg->data, lImg->cols * lImg->rows);
    zbar::ImageScanner* lScanner = new zbar::ImageScanner;
    std::vector<std::string>* lStrings = new std::vector<std::string>;
    std::vector<cv::Point>* lPoints = new std::vector<cv::Point>;
    lScanner->set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);
    lScanner->scan(*lImage);
    m_imageMap[imageId] = lImage;
    m_scannerMap[imageId] = lScanner;
    m_stringsMap[imageId] = lStrings;
    m_pointsMap[imageId] = lPoints;
}
//===============================================
void GZbar::getSymbol(std::string imageId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    zbar::Image* lImage = m_imageMap[imageId];
    std::vector<std::string>* lStrings = m_stringsMap[imageId];
    for(zbar::Image::SymbolIterator lSymbol = lImage->symbol_begin(); lSymbol != lImage->symbol_end(); ++lSymbol) {
        lStrings->push_back(lSymbol->get_type_name());
        lStrings->push_back(lSymbol->get_data());
    }
}
//===============================================
void GZbar::getLocation(std::string imageId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    zbar::Image* lImage = m_imageMap[imageId];
    std::vector<cv::Point>* lPoints = m_pointsMap[imageId];
    for(zbar::Image::SymbolIterator lSymbol = lImage->symbol_begin(); lSymbol != lImage->symbol_end(); ++lSymbol) {
        for(int i = 0; i < lSymbol->get_location_size(); i++) {
            cv::Point lPoint(lSymbol->get_location_x(i), lSymbol->get_location_y(i));
            lPoints->push_back(lPoint);
        }
    }
}
//===============================================
 std::vector<cv::Point>* GZbar::getPointsQRcode(std::string imageId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    return m_pointsMap[imageId];
}
//===============================================
void GZbar::showInfo(std::string imageId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::vector<std::string>* lStrings = m_stringsMap[imageId];
    std::vector<cv::Point>* lPoints = m_pointsMap[imageId];
    //
    for(int i = 0; i < lStrings->size(); i++) {
        std::cout << "qrcode_symbol[" << i << "]: " << lStrings->at(i) << "\n";
    }
    std::cout << "\n";
    //
    for(int i = 0; i < lPoints->size(); i++) {
        cv::Point lPoint = lPoints->at(i);
        std::cout << "qrcode_points[" << i << "]: " << lPoint.x << ", " << lPoint.y << "\n";
    }
}
//===============================================
void GZbar::deleteImage(std::string imageId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    zbar::Image* lImage = m_imageMap[imageId];
    zbar::ImageScanner* lScanner = m_scannerMap[imageId];
    std::vector<std::string>* lStrings = m_stringsMap[imageId];
    std::vector<cv::Point>* lPoints = m_pointsMap[imageId];
    delete lImage;
    delete lScanner;
    delete lStrings;
    delete lPoints;
    m_imageMap[imageId] = 0;
    m_scannerMap[imageId] = 0;
    m_stringsMap[imageId] = 0;
    m_pointsMap[imageId] = 0;
}
//===============================================
#endif
//===============================================
