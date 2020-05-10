//===============================================
#include "GProcess.h"
#include "GDebug.h"
//===============================================
int main(int argc, char** argv) {
    GDebug::Instance()->sep();
    GDebug::Instance()->write(__FUNCTION__, "()", _EOA_);
    GProcess::Instance()->process(argc, argv);
    return 0;
}
//===============================================
