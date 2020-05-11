//===============================================
#include "GProcess.h"
#include "GDebug.h"
#include "GOpenCV.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GProcess::~GProcess() {

}
//===============================================
GProcess* GProcess::Instance() {
    if(m_instance == 0) {
        m_instance = new GProcess;
    }
    return m_instance;
}
//===============================================
void GProcess::process(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    bool lRunFlag = 0;
    std::string lKey = "";
    for(int i = 1; i < argc;) {
    	std::string lKey = argv[i++];
        if(lKey == "test") {test(argc, argv); lRunFlag = 1; break;}
        // image
        if(lKey == "load_image") {loadImage(argc, argv); lRunFlag = 1; break;}
        if(lKey == "gaussian_blur_image") {gaussianBlurImage(argc, argv); lRunFlag = 1; break;}
        if(lKey == "canny_image") {cannyImage(argc, argv); lRunFlag = 1; break;}
        if(lKey == "pyr_down_image") {pyrDownImage(argc, argv); lRunFlag = 1; break;}
        if(lKey == "convert_image") {convertImage(argc, argv); lRunFlag = 1; break;}
        if(lKey == "get_pixel_image") {getPixelImage(argc, argv); lRunFlag = 1; break;}
        if(lKey == "set_pixel_image") {setPixelImage(argc, argv); lRunFlag = 1; break;}
        if(lKey == "get_string_image") {getStringImage(argc, argv); lRunFlag = 1; break;}
        if(lKey == "face_detection_image") {faceDetectionImage(argc, argv); lRunFlag = 1; break;}
        if(lKey == "face_recognition_image") {faceRecognitionImage(argc, argv); lRunFlag = 1; break;}
        if(lKey == "decode_qrcode_image") {decodeQRcodeImage(argc, argv); lRunFlag = 1; break;}
        // video
        if(lKey == "load_video") {loadVideo(argc, argv); lRunFlag = 1; break;}
        if(lKey == "get_property_video") {getPropertyVideo(argc, argv); lRunFlag = 1; break;}
        // video_writer
        if(lKey == "write_video") {writeVideo(argc, argv); lRunFlag = 1; break;}
        break;
    }
    if(lRunFlag == 0) help(argc, argv);
}
//===============================================
void GProcess::help(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    const char* lModule = "gp_opencv";
    printf("\n");
    printf("%s\n", "Description:");
    printf("\t%s\n", "Operations sur le module gp_opencv.");
    printf("\n");
    printf("%s\n", "Utilisation:");
    printf("\t\%s : %s\n", lModule, "afficher aide");
    // image
    printf("\t\%s %s : %s\n", lModule, "load_image", "charger image");
    printf("\t\%s %s : %s\n", lModule, "gaussian_blur_image", "appliquer filtre gaussien image");
    printf("\t\%s %s : %s\n", lModule, "canny_image", "appliquer filtre canny image");
    printf("\t\%s %s : %s\n", lModule, "pyr_down_image", "creer pyramide image");
    printf("\t\%s %s : %s\n", lModule, "convert_image", "convertir image");
    // video
    printf("\t\%s %s : %s\n", lModule, "load_video", "lire video");
    printf("\n");
}
//===============================================
void GProcess::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->test(argc, argv);
}
//===============================================
// image
//===============================================
void GProcess::loadImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/fruits.jpg");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    GOpenCV::Instance()->createWindow("org");
    GOpenCV::Instance()->showImage("org", "org");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
}
//===============================================
void GProcess::gaussianBlurImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/fruits.jpg");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    GOpenCV::Instance()->createImage("out");
    GOpenCV::Instance()->createWindow("out");
    GOpenCV::Instance()->gaussianBlurImage("org", "out");
    GOpenCV::Instance()->showImage("out", "out");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
    GOpenCV::Instance()->deleteImage("out");   
}
//===============================================
void GProcess::cannyImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/fruits.jpg");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    GOpenCV::Instance()->createImage("out");
    GOpenCV::Instance()->createWindow("out");
    GOpenCV::Instance()->convertImage("org", "out", cv::COLOR_BGR2GRAY);
    GOpenCV::Instance()->cannyImage("out", "out");
    GOpenCV::Instance()->showImage("out", "out");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
    GOpenCV::Instance()->deleteImage("out");   
}
//===============================================
void GProcess::pyrDownImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/fruits.jpg");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    GOpenCV::Instance()->createImage("out");
    GOpenCV::Instance()->createWindow("out");
    GOpenCV::Instance()->pyrDownImage("org", "out");
    GOpenCV::Instance()->showImage("out", "out");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
    GOpenCV::Instance()->deleteImage("out");   
}
//===============================================
void GProcess::convertImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/fruits.jpg");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    GOpenCV::Instance()->createImage("out");
    GOpenCV::Instance()->createWindow("out");
    GOpenCV::Instance()->convertImage("org", "out", cv::COLOR_BGR2GRAY);
    GOpenCV::Instance()->showImage("out", "out");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
    GOpenCV::Instance()->deleteImage("out");   
}
//===============================================
void GProcess::getPixelImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/fruits.jpg");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    GOpenCV::Instance()->createImage("out");
    GOpenCV::Instance()->createWindow("org");
    GOpenCV::Instance()->createWindow("out");
    GOpenCV::Instance()->convertImage("org", "out", cv::COLOR_BGR2GRAY);
    int lRed, lGreen, lBlue, lColor;
    GOpenCV::Instance()->getPixelImage("org", 10, 10, lRed, lGreen, lBlue);
    GOpenCV::Instance()->getPixelImage("org", 10, 10, lColor);
    std::cout << "rgb: " << lRed << ", " << lGreen << ", " << lBlue << "\n";
    std::cout << "gray: " << lColor << "\n";
    GOpenCV::Instance()->showImage("org", "org");
    GOpenCV::Instance()->showImage("out", "out");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
    GOpenCV::Instance()->deleteImage("out");   
}
//===============================================
void GProcess::setPixelImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/fruits.jpg");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    GOpenCV::Instance()->createImage("out");
    GOpenCV::Instance()->createWindow("org");
    GOpenCV::Instance()->createWindow("out");
    GOpenCV::Instance()->convertImage("org", "out", cv::COLOR_BGR2GRAY);
    for(int x = 10; x < 20; x++) {
        for(int y = 10; y < 20; y++) {
            GOpenCV::Instance()->setPixelImage("org", x, y, 255, 0, 0);
        }
    }
    for(int x = 10; x < 20; x++) {
        for(int y = 10; y < 20; y++) {
            GOpenCV::Instance()->setPixelImage("out", x, y, 255);
        }
    }
    GOpenCV::Instance()->showImage("org", "org");
    GOpenCV::Instance()->showImage("out", "out");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
    GOpenCV::Instance()->deleteImage("out");   
}
//===============================================
void GProcess::getStringImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/ocr.png");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    std::string lString = GOpenCV::Instance()->getStringImage("org", "eng");
    std::cout << lString << "\n";
    GOpenCV::Instance()->createWindow("org");
    GOpenCV::Instance()->showImage("org", "org");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
}
//===============================================
void GProcess::faceDetectionImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/face.png");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    GOpenCV::Instance()->faceDetectionImage("org", "org");
    GOpenCV::Instance()->createWindow("org");
    GOpenCV::Instance()->showImage("org", "org");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
}
//===============================================
void GProcess::faceRecognitionImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->loadImage("org", "data/img/face.jpg");
    if(GOpenCV::Instance()->checkEmptyImage("org") == 1) return;
    GOpenCV::Instance()->createWindow("org");
    GOpenCV::Instance()->showImage("org", "org");
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
}
//===============================================
void GProcess::decodeQRcodeImage(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::string lOrg = "org";
    GOpenCV::Instance()->loadImage(lOrg, "data/img/qrcode.png");
    if(GOpenCV::Instance()->checkEmptyImage(lOrg) == 1) return;
    GOpenCV::Instance()->createWindow(lOrg);
    GOpenCV::Instance()->decodeQRcodeImage(lOrg);
    GOpenCV::Instance()->showImage(lOrg, lOrg);
    GOpenCV::Instance()->waitKey(0);
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage(lOrg);   
}
//===============================================
// video
//===============================================
void GProcess::loadVideo(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->openVideo("video", "data/video/american_foot.avi");
    GOpenCV::Instance()->createImage("org");
    GOpenCV::Instance()->createWindow("org");
    while(1) {
        GOpenCV::Instance()->getImageVideo("video", "org");    
        if(GOpenCV::Instance()->checkEmptyImage("org") == 1) break;
        GOpenCV::Instance()->showImage("org", "org");
        if(GOpenCV::Instance()->waitKey(33) != -1) break;
    }
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
    GOpenCV::Instance()->deleteVideo("video");   
}
//===============================================
void GProcess::getPropertyVideo(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->openVideo("video", "data/video/american_foot.avi");
    GOpenCV::Instance()->createImage("org");
    GOpenCV::Instance()->createWindow("org");
    
    int lFps = (int)GOpenCV::Instance()->getPropertyVideo("video", cv::CAP_PROP_FPS);
    int lWidth = (int)GOpenCV::Instance()->getPropertyVideo("video", cv::CAP_PROP_FRAME_WIDTH);
    int lHeight = (int)GOpenCV::Instance()->getPropertyVideo("video", cv::CAP_PROP_FRAME_HEIGHT);
    
    std::cout << "fps: " << lFps << "\n";
    std::cout << "width: " << lWidth << "\n";
    std::cout << "height: " << lHeight << "\n";
    
    while(1) {
        GOpenCV::Instance()->getImageVideo("video", "org");    
        if(GOpenCV::Instance()->checkEmptyImage("org") == 1) break;
        GOpenCV::Instance()->showImage("org", "org");
        if(GOpenCV::Instance()->waitKey(33) != -1) break;
    }
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
    GOpenCV::Instance()->deleteVideo("video");   
}
//===============================================
// video_writer
//===============================================
void GProcess::writeVideo(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    GOpenCV::Instance()->openVideo("video", "data/video/american_foot.avi");
    
    int lFps = (int)GOpenCV::Instance()->getPropertyVideo("video", cv::CAP_PROP_FPS);
    int lWidth = (int)GOpenCV::Instance()->getPropertyVideo("video", cv::CAP_PROP_FRAME_WIDTH);
    int lHeight = (int)GOpenCV::Instance()->getPropertyVideo("video", cv::CAP_PROP_FRAME_HEIGHT);
    
    GOpenCV::Instance()->openVideoWriter("writer", "data/video/canny.avi", cv::VideoWriter::fourcc('M','J','P','G'), lFps, lWidth, lHeight);
    GOpenCV::Instance()->createImage("org");
    GOpenCV::Instance()->createImage("out");
    GOpenCV::Instance()->createImage("canny");
    
    GOpenCV::Instance()->createWindow("out");
    while(1) {
        GOpenCV::Instance()->getImageVideo("video", "org");    
        if(GOpenCV::Instance()->checkEmptyImage("org") == 1) break;
        GOpenCV::Instance()->gaussianBlurImage("org", "org");
        GOpenCV::Instance()->convertImage("org", "out", cv::COLOR_BGR2GRAY);
        GOpenCV::Instance()->cannyImage("out", "out");
        GOpenCV::Instance()->convertImage("out", "canny", cv::COLOR_GRAY2BGR);
        GOpenCV::Instance()->writeImageVideoWriter("writer", "canny");
        GOpenCV::Instance()->showImage("out", "out");
        if(GOpenCV::Instance()->waitKey(33) != -1) break;
    }
    GOpenCV::Instance()->destroyWindows();   
    GOpenCV::Instance()->deleteImage("org");   
    GOpenCV::Instance()->deleteImage("out");   
    GOpenCV::Instance()->deleteImage("canny");   
    GOpenCV::Instance()->deleteVideo("video");   
    GOpenCV::Instance()->deleteVideoWriter("writer");   
}
//===============================================
