//===============================================
#ifndef _GProcessImagePyrDown_
#define _GProcessImagePyrDown_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessImagePyrDown : public GProcess {
public:
    GProcessImagePyrDown();
    ~GProcessImagePyrDown();

public:
    static GProcessImagePyrDown* Instance();
    void run(int argc, char** argv);

private:
    static GProcessImagePyrDown* m_instance;
};
//===============================================
#endif
//===============================================
