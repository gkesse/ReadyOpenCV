//================================================
#ifndef _GFile_
#define _GFile_
//================================================
#include "GInclude.h"
//================================================
class GFile {
private:
    GFile();

public:
    ~GFile();
    static GFile* Instance();
    void test(int argc, char** argv);
    // ifstream
    void createIfstream(std::string fileId, std::string filename);
    void showData(std::string fileId);
    std::vector<std::vector<std::string>> getData(std::string fileId, char sep);
    void deleteIfstream(std::string fileId);

private:
    const char* __CLASSNAME__;
    static GFile* m_instance;
    std::map<std::string, std::ifstream*> m_ifstreamMap;
};
//===============================================
#endif
//================================================
