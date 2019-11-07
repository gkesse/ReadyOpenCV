//===============================================
#ifndef _GProcessImagePrintNonZero_
#define _GProcessImagePrintNonZero_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessImagePrintNonZero : public GProcess {
public:
    GProcessImagePrintNonZero();
    ~GProcessImagePrintNonZero();

public:
    static GProcessImagePrintNonZero* Instance();
    void run(int argc, char** argv);

private:
    static GProcessImagePrintNonZero* m_instance;
};
//===============================================
#endif
//===============================================
