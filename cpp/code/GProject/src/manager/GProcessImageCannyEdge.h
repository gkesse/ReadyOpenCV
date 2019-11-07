//===============================================
#ifndef _GProcessImageCannyEdge_
#define _GProcessImageCannyEdge_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessImageCannyEdge : public GProcess {
public:
    GProcessImageCannyEdge();
    ~GProcessImageCannyEdge();

public:
    static GProcessImageCannyEdge* Instance();
    void run(int argc, char** argv);

private:
    static GProcessImageCannyEdge* m_instance;
};
//===============================================
#endif
//===============================================
