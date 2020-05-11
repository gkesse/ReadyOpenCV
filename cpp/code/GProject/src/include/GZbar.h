//================================================
#ifndef _GZbar_
#define _GZbar_
//================================================
#include "GInclude.h"
//================================================
#if defined(_GUSE_ZBAR_ON_)
//================================================
class GZbar {
private:
    GZbar();

public:
    ~GZbar();
    static GZbar* Instance();
    void test(int argc, char** argv);
    // Image
    void createImage(std::string imageId, std::string imgId);
    void getSymbol(std::string imageId);
    void getLocation(std::string imageId);
    std::vector<cv::Point>* getPointsQRcode(std::string imageId);
    void showInfo(std::string imageId);
    void deleteImage(std::string imageId);

private:
    const char* __CLASSNAME__;
    static GZbar* m_instance;
    std::map<std::string, zbar::Image*> m_imageMap;
    std::map<std::string, zbar::ImageScanner*> m_scannerMap;
    std::map<std::string, std::vector<std::string>*> m_stringsMap;
    std::map<std::string, std::vector<cv::Point>*> m_pointsMap;
};
//===============================================
#endif
//===============================================
#endif
//================================================
