//===============================================
#ifndef _GProcessProjectImage_
#define _GProcessProjectImage_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessProjectImage : public GProcess {
public:
    GProcessProjectImage();
    ~GProcessProjectImage();

public:
    static GProcessProjectImage* Instance();
    void run(int argc, char** argv);

private:
    static GProcessProjectImage* m_instance;
};
//===============================================
#endif
//===============================================
