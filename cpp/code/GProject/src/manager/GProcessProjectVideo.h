//===============================================
#ifndef _GProcessProjectVideo_
#define _GProcessProjectVideo_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessProjectVideo : public GProcess {
public:
    GProcessProjectVideo();
    ~GProcessProjectVideo();

public:
    static GProcessProjectVideo* Instance();
    void run(int argc, char** argv);

private:
    static GProcessProjectVideo* m_instance;
};
//===============================================
#endif
//===============================================
