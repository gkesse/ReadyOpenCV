//===============================================
#ifndef _GProcessImageROI_
#define _GProcessImageROI_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessImageROI : public GProcess {
public:
    GProcessImageROI();
    ~GProcessImageROI();

public:
    static GProcessImageROI* Instance();
    void run(int argc, char** argv);

private:
    static GProcessImageROI* m_instance;
};
//===============================================
#endif
//===============================================
