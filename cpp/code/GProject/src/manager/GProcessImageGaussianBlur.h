//===============================================
#ifndef _GProcessImageGaussianBlur_
#define _GProcessImageGaussianBlur_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessImageGaussianBlur : public GProcess {
public:
    GProcessImageGaussianBlur();
    ~GProcessImageGaussianBlur();

public:
    static GProcessImageGaussianBlur* Instance();
    void run(int argc, char** argv);

private:
    static GProcessImageGaussianBlur* m_instance;
};
//===============================================
#endif
//===============================================
