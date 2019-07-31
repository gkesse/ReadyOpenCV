//===============================================
#ifndef _GProcessImageAccessPixel_
#define _GProcessImageAccessPixel_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessImageAccessPixel : public GProcess {
public:
    GProcessImageAccessPixel();
    ~GProcessImageAccessPixel();

public:
    static GProcessImageAccessPixel* Instance();
    void run(int argc, char** argv);

private:
    static GProcessImageAccessPixel* m_instance;
};
//===============================================
#endif
//===============================================
