//===============================================
#include "GOptions.h"
#include "GProcess.h"
//===============================================
int main(int argc, char** argv) {
    GOptions()->GetArgs(argc, argv);
    GProcess()->Run(argc, argv);
    return 0;
}
//===============================================
