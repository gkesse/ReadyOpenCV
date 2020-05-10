//================================================
#ifndef _GOpenCV_
#define _GOpenCV_
//================================================
#include "GInclude.h"
//================================================
#if defined(_GUSE_OPENCV_ON_)
//================================================
class GOpenCV {
private:
    GOpenCV();

public:
    ~GOpenCV();
    static GOpenCV* Instance();
    void test(int argc, char** argv);
    // image
    void loadImage(std::string imgId, std::string filename);
    void createImage(std::string imgId);
    cv::Mat* getImage(std::string imgId); 
    bool checkEmptyImage(std::string imgId);
    void showImage(std::string imgId, std::string windowId);
    void gaussianBlurImage(std::string imgId, std::string outId);
    void cannyImage(std::string imgId, std::string outId);
    void pyrDownImage(std::string imgId, std::string outId);
    void logPolarImage(std::string imgId, std::string outId, int x, int y);
    void convertImage(std::string imgId, std::string outId, int convertId);
    void getPixelImage(std::string imgId, int x, int y, int& red, int& green, int& blue);
    void getPixelImage(std::string imgId, int x, int y, int& color);
    void setPixelImage(std::string imgId, int x, int y, int red, int green, int blue);
    void setPixelImage(std::string imgId, int x, int y, int color);
    std::string getStringImage(std::string imgId, std::string language);
    void deleteImage(std::string imgId);
    // video
    void openVideo(std::string videoId, std::string filename);
    bool checkOpenVideo(std::string videoId);
    void getImageVideo(std::string videoId, std::string imgId);
    void setPropertyVideo(std::string videoId, int propId, double value);
    double getPropertyVideo(std::string videoId, int propId);
    void deleteVideo(std::string videoId);
    // video_writer
    void openVideoWriter(std::string videoWriterId, std::string filename, int fourcc, double fps, int width, int height);
    void writeImageVideoWriter(std::string videoWriterId, std::string imgId);
    void deleteVideoWriter(std::string videoWriterId);
    // delay
    int waitKey(int delay);
    // window
    void createWindow(std::string windowId);
    void destroyWindows();

private:
    const char* __CLASSNAME__;
    static GOpenCV* m_instance;
    std::map<std::string, cv::Mat*> m_imgMap;
    std::map<std::string, cv::VideoCapture*> m_videoMap;
    std::map<std::string, cv::VideoWriter*> m_videoWriterMap;
};
//===============================================
#endif
//===============================================
#endif
//================================================
