//================================================
#ifndef _GShell_
#define _GShell_
//================================================
#include "GInclude.h"
//================================================
class GShell {
private:
    GShell();

public:
    ~GShell();
    static GShell* Instance();
    void test(int argc, char** argv);
    void run(const char* command, char* output, int size, int shift);

private:
#if defined(__WIN32)
    void testWin(int argc, char** argv);
#elif defined(__unix)
    void testUnix(int argc, char** argv);
#endif

private:
    const char* __CLASSNAME__;
    static GShell* m_instance;
};
//================================================
#endif
//================================================
