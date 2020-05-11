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
    void convertGrayImage(std::string imgId, std::string outId);
    void convertColorImage(std::string imgId, std::string outId);
    void getPixelImage(std::string imgId, int x, int y, int& red, int& green, int& blue);
    void getPixelImage(std::string imgId, int x, int y, int& color);
    void setPixelImage(std::string imgId, int x, int y, int red, int green, int blue);
    void setPixelImage(std::string imgId, int x, int y, int color);
    void resizeImage(std::string imgId, std::string outId, int width, int height);
    void resizeImage(std::string imgId, std::string outId, int width, int height, int interpolation);
    void resizeImage(std::string imgId, std::string outId, double factor);
    void resizeImage(std::string imgId, std::string outId, double factor, int interpolation);
    void equalizeHistImage(std::string imgId, std::string outId);
    void drawRectImage(std::string imgId, std::string rectsId, int red, int green, int blue, int thickness);
    void drawCircleImage(std::string imgId, std::string rectsId, int red, int green, int blue, int thickness);
    std::string getStringImage(std::string imgId, std::string language);
    void faceDetectionImage(std::string imgId, std::string outId);
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
    // CascadeClassifier 
    void createCascadeClassifier(std::string classifierId, std::string filename);
    void detectCascadeClassifier(std::string imgId, std::string classifierId);
    void detectCascadeClassifier(std::string imgId, std::string eyeClassifierId, std::string faceClassifierId, int iFaceRect);
    void detectCascadeClassifier(std::string imgId, std::string eyeClassifierId, std::string faceClassifierId);
    std::vector<cv::Rect>* getRectsCascadeClassifier(std::string classifierId);
    void deleteCascadeClassifier(std::string classifierId);

private:
    const char* __CLASSNAME__;  
    static GOpenCV* m_instance;
    std::map<std::string, cv::Mat*> m_imgMap;
    std::map<std::string, cv::VideoCapture*> m_videoMap;
    std::map<std::string, cv::VideoWriter*> m_videoWriterMap;
    std::map<std::string, cv::CascadeClassifier*> m_classifierMap;
    std::map<std::string, std::vector<cv::Rect>*> m_rectsMap;
}; 
//===============================================
#endif
//===============================================
#endif
//================================================
