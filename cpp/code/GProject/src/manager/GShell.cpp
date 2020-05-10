//===============================================
#include "GShell.h"
#include "GDebug.h"
//===============================================
GShell* GShell::m_instance = 0;
//===============================================
GShell::GShell() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GShell::~GShell() {

}
//===============================================
GShell* GShell::Instance() {
    if(m_instance == 0) {
        m_instance = new GShell;
    }
    return m_instance;
}
//===============================================
void GShell::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
#if defined(__WIN32)
    testWin(argc, argv);
#elif defined(__unix)
    testUnix(argc, argv);
#endif
}
//===============================================
#if defined(__WIN32)
void GShell::testWin(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    char lCommand[256];
    char lOuput[256];

    sprintf(lCommand, "%s", "echo %HOMEDRIVE%%HOMEPATH%");
    run(lCommand, lOuput, 1023, 1);
    std::cout << lOuput << "\n";
}
#endif
//===============================================
#if defined(__unix)
void GShell::testUnix(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    char lCommand[256];
    char lOuput[256];

    sprintf(lCommand, "%s", "echo $HOME");
    run(lCommand, lOuput, 255, 1);
    std::cout << lOuput << "\n";
}
#endif
//===============================================
void GShell::run(const char* command, char* output, int size, int shift) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    FILE* lpFile = popen(command, "r");
    if(output != 0) {
        int lBytes = fread(output, 1, size, lpFile);
        if(lBytes >= 1) {
            output[lBytes] = 0;
            if(shift == 1) output[lBytes - 1] = 0;
        }
    }
    pclose(lpFile);
}
//===============================================
