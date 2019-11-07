//===============================================
#ifndef _GProcessImageCombineOperator_
#define _GProcessImageCombineOperator_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessImageCombineOperator : public GProcess {
public:
    GProcessImageCombineOperator();
    ~GProcessImageCombineOperator();

public:
    static GProcessImageCombineOperator* Instance();
    void run(int argc, char** argv);

private:
    static GProcessImageCombineOperator* m_instance;
};
//===============================================
#endif
//===============================================
