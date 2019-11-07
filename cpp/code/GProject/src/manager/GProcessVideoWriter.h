//===============================================
#ifndef _GProcessVideoWriter_
#define _GProcessVideoWriter_
//===============================================
#include "GProcess.h"
//===============================================
class GProcessVideoWriter : public GProcess {
public:
    GProcessVideoWriter();
    ~GProcessVideoWriter();

public:
    static GProcessVideoWriter* Instance();
    void run(int argc, char** argv);

private:
    static GProcessVideoWriter* m_instance;
};
//===============================================
#endif
//===============================================
