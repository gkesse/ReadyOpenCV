//===============================================
#ifndef _GProcessImageSumPlane_
#define _GProcessImageSumPlane_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessImageSumPlane : public GProcess {
public:
    GProcessImageSumPlane();
    ~GProcessImageSumPlane();

public:
    static GProcessImageSumPlane* Instance();
    void run(int argc, char** argv);

private:
    static GProcessImageSumPlane* m_instance;
};
//===============================================
#endif
//===============================================
