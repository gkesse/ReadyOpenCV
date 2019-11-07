//===============================================
#ifndef _GProcessTrackbar_
#define _GProcessTrackbar_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessTrackbar : public GProcess {
public:
    GProcessTrackbar();
    ~GProcessTrackbar();

public:
    static GProcessTrackbar* Instance();
    void run(int argc, char** argv);

private:
    static GProcessTrackbar* m_instance;
};
//===============================================
#endif
//===============================================
