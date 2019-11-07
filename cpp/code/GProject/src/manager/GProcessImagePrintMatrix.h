//===============================================
#ifndef _GProcessImagePrintMatrix_
#define _GProcessImagePrintMatrix_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessImagePrintMatrix : public GProcess {
public:
    GProcessImagePrintMatrix();
    ~GProcessImagePrintMatrix();

public:
    static GProcessImagePrintMatrix* Instance();
    void run(int argc, char** argv);

private:
    static GProcessImagePrintMatrix* m_instance;
};
//===============================================
#endif
//===============================================
