//===============================================
#ifndef _GProcessTest_
#define _GProcessTest_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessTest : public GProcess {
public:
    GProcessTest();
    ~GProcessTest();

public:
    static GProcessTest* Instance();
    void run(int argc, char** argv);

private:
    static GProcessTest* m_instance;
};
//===============================================
#endif
//===============================================
