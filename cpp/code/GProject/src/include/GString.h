//================================================
#ifndef _GString_
#define _GString_
//================================================
#include "GInclude.h"
//================================================
class GString {
private:
    GString();

public:
    ~GString();
    static GString* Instance();
    void test(int argc, char** argv);
    // string
    std::string trim(std::string str);
    std::string ltrim(std::string str);
    std::string rtrim(std::string str);
    std::vector<std::string> split(std::string str, char sep);
    std::string getFilename(std::string path);

private:
    const char* __CLASSNAME__;
    static GString* m_instance;
};
//===============================================
#endif
//================================================
