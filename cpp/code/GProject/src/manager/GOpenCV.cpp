//===============================================
#include "GOpenCV.h"
#include "GTesseract.h"
#include "GZbar.h"
#include "GFile.h"
#include "GString.h"
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
    std::string lAruco = "lAruco";
    std::string lImg = "lImg";
    loadImage(lImg, "data/img/face.png");
    showImage(lImg, lImg);
    waitKey(0);
    deleteImage(lImg);
    destroyWindows();
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
void GOpenCV::convertGrayImage(std::string imgId, std::string outId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::cvtColor(*lImg, *lOut, cv::COLOR_BGR2GRAY);
}
//===============================================
void GOpenCV::convertColorImage(std::string imgId, std::string outId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::cvtColor(*lImg, *lOut, cv::COLOR_GRAY2BGR);
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
void GOpenCV::resizeImage(std::string imgId, std::string outId, int width, int height) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::resize(*lImg, *lOut, cv::Size(width, height));
}
//===============================================
void GOpenCV::resizeImage(std::string imgId, std::string outId, int width, int height, int interpolation) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::resize(*lImg, *lOut, cv::Size(width, height), 0, 0, interpolation);
}
//===============================================
void GOpenCV::resizeImage(std::string imgId, std::string outId, double factor) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::resize(*lImg, *lOut, cv::Size(), factor, factor);
}
//===============================================
void GOpenCV::resizeImage(std::string imgId, std::string outId, double factor, int interpolation) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::resize(*lImg, *lOut, cv::Size(), factor, factor, interpolation);
}
//===============================================
void GOpenCV::equalizeHistImage(std::string imgId, std::string outId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat* lOut = m_imgMap[outId];
    cv::equalizeHist(*lImg, *lOut);
}
//===============================================
void GOpenCV::drawRectImage(std::string imgId, std::string rectsId, int red, int green, int blue, int thickness) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    std::vector<cv::Rect>* lRects = m_rectsMap[rectsId];
    for(int i = 0; i < lRects->size(); i++) {
        cv::Rect lRect = lRects->at(i);
        cv::rectangle(*lImg, lRect, cv::Scalar((blue), (green), (red), 0), thickness);
    }
}
//===============================================
void GOpenCV::drawCircleImage(std::string imgId, std::string rectsId, int red, int green, int blue, int thickness) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    std::vector<cv::Rect>* lRects = m_rectsMap[rectsId];
    for(int i = 0; i < lRects->size(); i++) {
        cv::Rect lRect = lRects->at(i);
        cv::Point lCenter = cv::Point(int(lRect.x + lRect.width*0.5), int(lRect.y + lRect.height*0.5)); 
        int lRadius = int((lRect.width + lRect.height)*0.25); 
        cv::circle(*lImg, lCenter, lRadius, cv::Scalar((blue), (green), (red), 0), thickness);
    }
}
//===============================================
void GOpenCV::saveImage(std::string imgId, std::string rectsId, std::string path) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    std::vector<cv::Rect>* lRects = m_rectsMap[rectsId];
    for(int i = 0; i < lRects->size(); i++) {
        cv::Rect lRect = lRects->at(i);
        cv::Mat lOut = (*lImg)(lRect);
        cv::Mat lResizeOut;
        cv::resize(lOut, lResizeOut, cv::Size(100, 100));
        cv::imwrite(path, lResizeOut);
        break;
    }
}
//===============================================
std::string GOpenCV::getStringImage(std::string imgId, std::string language) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GTesseract::Instance()->createTesseract(imgId, language);
    GTesseract::Instance()->setImageOpenCV(imgId, imgId, "78");
    std::string lString = GTesseract::Instance()->getString(imgId);
    GTesseract::Instance()->deleteTesseract(imgId);
    return lString;
}
//===============================================
void GOpenCV::faceDetectionImage(std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::string lFaceDetect = imgId + "lFaceDetect";
    std::string lEyeDetect = imgId + "lEyeDetect";
    std::string lGray = imgId + "lGray";
    std::string lFaceDetectFile = "data/haarcascades/haarcascade_frontalface_alt.xml";
    std::string lEyeDetectFile = "data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
    
    createCascadeClassifier(lFaceDetect, lFaceDetectFile);
    createCascadeClassifier(lEyeDetect, lEyeDetectFile);
    createImage(lGray);
    
    convertGrayImage(imgId, lGray);
    equalizeHistImage(lGray, lGray);
    detectCascadeClassifier(lGray, lFaceDetect);
    detectCascadeClassifier(lGray, lEyeDetect, lFaceDetect);
    drawRectImage(imgId, lFaceDetect, 0, 255, 0, 2);
    drawCircleImage(imgId, lFaceDetect, 255, 0, 0, 2);
    drawRectImage(imgId, lEyeDetect, 255, 255, 0, 2);
    drawCircleImage(imgId, lEyeDetect, 0, 0, 255, 2); 
    
    std::vector<cv::Rect>* lFaceRects = getRectsCascadeClassifier(lFaceDetect);
    std::vector<cv::Rect>* lEyeRects = getRectsCascadeClassifier(lEyeDetect);
    std::cout << "lFaceRects: " << lFaceRects->size() << "\n";
    std::cout << "lEyeRects: " << lEyeRects->size() << "\n";
    
    deleteCascadeClassifier(lFaceDetect);
    deleteCascadeClassifier(lEyeDetect);
    deleteImage(lGray);
}
//===============================================
void GOpenCV::saveOneFaceDetectionImage(std::string fileId, std::string outPath) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::vector<std::vector<std::string>> lStringsMap = GFile::Instance()->getData(fileId, ';');
    for(int i = 0; i < lStringsMap.size(); i++) {
        std::vector<std::string> lStringMap = lStringsMap.at(i);
        std::string lPath = lStringMap[0];
        std::string lImg = fileId + std::to_string(i);
        std::string lFilename = GString::Instance()->getFilename(lPath);
        lFilename = outPath + "/" + lFilename;
        loadImage(lImg, lPath);
        saveOneFaceDetectionImageFile(lImg, lFilename);
        deleteImage(lImg);
    }
}
//===============================================
void GOpenCV::loadOneFaceDetectionImage(std::string modelId, std::string fileId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::vector<std::vector<std::string>> lStringsMap = GFile::Instance()->getData(fileId, ';');
    std::vector<cv::Mat>* lImgs = m_imgsMap[modelId];
    std::vector<int>* lIndices = m_indicesMap[modelId];
    std::map<int, std::string>* lStrings = m_stringsMap[modelId];

    for(int i = 0; i < lStringsMap.size(); i++) {
        std::vector<std::string> lStringMap = lStringsMap.at(i);
        std::string lPath = lStringMap[0];
        std::string lIndice = lStringMap[1];
        std::string lName = lStringMap[2];
        int lIndiceInt = atoi(lIndice.c_str());
        cv::Mat lImg = cv::imread(lPath, cv::IMREAD_GRAYSCALE);
        lImgs->push_back(lImg);
        lIndices->push_back(lIndiceInt);
        (*lStrings)[lIndiceInt] = lName;
    }
}
//===============================================
void GOpenCV::saveOneFaceDetectionImageFile(std::string imgId, std::string filename) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::string lFaceDetect = imgId + "lFaceDetect";
    std::string lGray = imgId + "lGray";
    std::string lFaceDetectFile = "data/haarcascades/haarcascade_frontalface_alt.xml";
    
    createCascadeClassifier(lFaceDetect, lFaceDetectFile);
    createImage(lGray);
    
    convertGrayImage(imgId, lGray);
    equalizeHistImage(lGray, lGray);
    detectCascadeClassifier(lGray, lFaceDetect);
    saveImage(imgId, lFaceDetect, filename);
    
    deleteCascadeClassifier(lFaceDetect);
    deleteImage(lGray);
}
//===============================================
void GOpenCV::faceRecognitionImage(std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::string lFile = imgId + "lFile";
    std::string lDatabase = "data/rec/face_data.txt";
    std::string lModel = imgId + "lModel";
    
    createEigenFaceRecognizer(lModel);
    GFile::Instance()->createIfstream(lFile, lDatabase);
    
    loadOneFaceDetectionImage(lModel, lFile);
    trainFaceRecognizer(lModel);
    int lIndice = predictFaceRecognizer(lModel, imgId);
    std::string lName = nameFaceRecognizer(lModel, lIndice);
    std::cout << "lIndice: " << lIndice << "\n";
    std::cout << "lName: " << lName << "\n";
    
    GFile::Instance()->deleteIfstream(lFile);
    deleteEigenFaceRecognizer(lModel);
}
//===============================================
void GOpenCV::decodeQRcodeImage(std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::string lGray = imgId + "lGray";
    std::string lImage = imgId + "lImage";

    createImage(lGray);
    
    convertGrayImage(imgId, lGray);
    GZbar::Instance()->createImage(lImage, lGray);
    GZbar::Instance()->getSymbol(lImage);
    GZbar::Instance()->getLocation(lImage);
    GZbar::Instance()->showInfo(lImage);
    drawQRcodeImage(imgId, lImage, 255, 0, 0, 2);
        
    deleteImage(lGray);
    GZbar::Instance()->deleteImage(lImage);
}
//===============================================
void GOpenCV::drawQRcodeImage(std::string imgId, std::string imageId, int red, int green, int blue, int thickness) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    std::vector<cv::Point>* lPoints = GZbar::Instance()->getPointsQRcode(imageId);
    cv::RotatedRect lRotatedRect = cv::minAreaRect(*lPoints);
    cv::Rect lQRcodeRect = lRotatedRect.boundingRect();
    cv::rectangle(*lImg, lQRcodeRect, cv::Scalar(blue, green, red, 0), thickness);
}
//===============================================
void GOpenCV::drawQRcodeRotatedRectImage(std::string imgId, std::string imageId, int red, int green, int blue, int thickness) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    std::vector<cv::Point>* lPoints = GZbar::Instance()->getPointsQRcode(imageId);
    cv::RotatedRect lRotatedRect = cv::minAreaRect(*lPoints);
    cv::Point2f lRotatedPoints[4];
    lRotatedRect.points(lRotatedPoints);
    for (int i = 0; i < 4; i++) {
        cv::line(*lImg, lRotatedPoints[i], lRotatedPoints[(i+1)%4], cv::Scalar(blue, green, red, 0), 2);
    }
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
    cv::namedWindow(windowId, cv::WINDOW_AUTOSIZE);
}
//===============================================
// window
//===============================================
void GOpenCV::destroyWindows() {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::destroyAllWindows();
}
//===============================================
// CascadeClassifier
//===============================================
void GOpenCV::createCascadeClassifier(std::string classifierId, std::string filename) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::CascadeClassifier* lClassifier = new cv::CascadeClassifier;
    std::vector<cv::Rect>* lRects = new std::vector<cv::Rect>;
    lClassifier->load(filename.c_str());
    m_classifierMap[classifierId] = lClassifier;
    m_rectsMap[classifierId] = lRects;
}
//===============================================
void GOpenCV::detectCascadeClassifier(std::string imgId, std::string classifierId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::CascadeClassifier* lClassifier = m_classifierMap[classifierId];
    std::vector<cv::Rect>* lRects = m_rectsMap[classifierId];
    lClassifier->detectMultiScale(*lImg, *lRects, 1.1, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(25, 25));
}
//===============================================
void GOpenCV::detectCascadeClassifier(std::string imgId, std::string eyeClassifierId, std::string faceClassifierId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Mat* lImg = m_imgMap[imgId];
    cv::CascadeClassifier* lEyeClassifier = m_classifierMap[eyeClassifierId];
    std::vector<cv::Rect>* lEyeRects = m_rectsMap[eyeClassifierId];
    std::vector<cv::Rect>* lFaceRects = m_rectsMap[faceClassifierId];
    for(int i = 0; i < lFaceRects->size(); i++) {
        cv::Rect lFaceRect = lFaceRects->at(i);
        cv::Mat lRoiImg = (*lImg)(lFaceRect);
        std::vector<cv::Rect> lRects;
        lEyeClassifier->detectMultiScale(lRoiImg, lRects, 1.1, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(25, 25));
        for(int j = 0; j < lRects.size(); j++) {
            cv::Rect lRect = lRects[j];
            lRect.x += lFaceRect.x;
            lRect.y += lFaceRect.y;
            lEyeRects->push_back(lRect);
        }
    }
}
//===============================================
std::vector<cv::Rect>* GOpenCV::getRectsCascadeClassifier(std::string classifierId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    return m_rectsMap[classifierId];
}
//===============================================
void GOpenCV::deleteCascadeClassifier(std::string classifierId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::CascadeClassifier* lClassifier = m_classifierMap[classifierId];
    std::vector<cv::Rect>* lRects = m_rectsMap[classifierId];
    delete lClassifier;
    delete lRects;
    m_classifierMap[classifierId] = 0;
    m_rectsMap[classifierId] = 0;
}
//===============================================
// EigenFaceRecognizer
//===============================================
void GOpenCV::createEigenFaceRecognizer(std::string modelId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Ptr<cv::face::EigenFaceRecognizer> lModel = cv::face::EigenFaceRecognizer::create();
    std::vector<cv::Mat>* lImgs =  new std::vector<cv::Mat>;
    std::vector<int>* lIndices = new std::vector<int>;
    std::map<int, std::string>* lStrings = new std::map<int, std::string>;
    m_modelMap[modelId] = lModel;
    m_imgsMap[modelId] = lImgs;
    m_indicesMap[modelId] = lIndices;
    m_stringsMap[modelId] = lStrings;
}
//===============================================
void GOpenCV::trainFaceRecognizer(std::string modelId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Ptr<cv::face::EigenFaceRecognizer> lModel = m_modelMap[modelId];
    std::vector<cv::Mat>* lImgs =  m_imgsMap[modelId];
    std::vector<int>* lIndices = m_indicesMap[modelId];
    lModel->train(*lImgs, *lIndices);
}
//===============================================
int GOpenCV::predictFaceRecognizer(std::string modelId, std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Ptr<cv::face::EigenFaceRecognizer> lModel = m_modelMap[modelId];
    cv::Mat* lImg = m_imgMap[imgId];
    cv::Mat lGray;
    cv::cvtColor(*lImg, lGray, cv::COLOR_BGR2GRAY);
    int lIndice = lModel->predict(lGray);
    return lIndice;
}
//===============================================
std::string GOpenCV::nameFaceRecognizer(std::string modelId, int indice) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::map<int, std::string>* lStrings = m_stringsMap[modelId];
    std::string lString = (*lStrings)[indice];
    return lString;
}
//===============================================
void GOpenCV::eigenValuesFaceRecognizer(std::string modelId, std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Ptr<cv::face::EigenFaceRecognizer> lModel = m_modelMap[modelId];
    cv::Mat* lImg = m_imgMap[imgId];
}
//===============================================
void GOpenCV::eigenVectorsFaceRecognizer(std::string modelId, std::string imgId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    cv::Ptr<cv::face::EigenFaceRecognizer> lModel = m_modelMap[modelId];
    cv::Mat* lImg = m_imgMap[imgId];
}
//===============================================
void GOpenCV::deleteEigenFaceRecognizer(std::string modelId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::vector<cv::Mat>* lImgs =  m_imgsMap[modelId];
    std::vector<int>* lIndices = m_indicesMap[modelId];
    std::map<int, std::string>* lStrings = m_stringsMap[modelId];
    delete lImgs;
    delete lIndices;
    m_imgsMap[modelId] = 0;
    m_indicesMap[modelId] = 0;
    m_stringsMap[modelId] = 0;
}
//===============================================
// aruco
//===============================================
void GOpenCV::createArucoDictionary(std::string arucoId) {
    cv::Ptr<cv::aruco::Dictionary> lDictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
    m_arucoDicMap[arucoId] = lDictionary;
}
//===============================================
void GOpenCV::generateArucoDictionary(std::string arucoId, std::string imgId) {
    cv::Ptr<cv::aruco::Dictionary> lDictionary = m_arucoDicMap[arucoId];
    cv::Mat* lImg = m_imgMap[imgId];
    cv::aruco::drawMarker(lDictionary, 33, 200, *lImg, 1);    
}
//===============================================
#endif
//===============================================
