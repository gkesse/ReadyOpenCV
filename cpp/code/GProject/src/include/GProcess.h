//================================================
#ifndef _GProcess_
#define _GProcess_
//================================================
#include "GInclude.h"
//================================================
class GProcess {
private:
    GProcess();

public:
    ~GProcess();
    static GProcess* Instance();
    void process(int argc, char** argv);
    void test(int argc, char** argv);
    // image
    void loadImage(int argc, char** argv);
    void gaussianBlurImage(int argc, char** argv);
    void cannyImage(int argc, char** argv);
    void pyrDownImage(int argc, char** argv);
    void convertImage(int argc, char** argv);
    void getPixelImage(int argc, char** argv);
    void setPixelImage(int argc, char** argv);
    void getStringImage(int argc, char** argv);
    void faceDetectionImage(int argc, char** argv);
    void faceRecognitionImage(int argc, char** argv);
    // video
    void loadVideo(int argc, char** argv);
    void getPropertyVideo(int argc, char** argv);
    // video_writer
    void writeVideo(int argc, char** argv);

private:
    void help(int argc, char** argv);

private:
    const char* __CLASSNAME__;
    static GProcess* m_instance;
};
//===============================================
#endif
//================================================
