//===============================================
#include "GFile.h"
#include "GString.h"
#include "GDebug.h"
//===============================================
GFile* GFile::m_instance = 0;
//===============================================
GFile::GFile() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GFile::~GFile() {

}
//===============================================
GFile* GFile::Instance() {
    if(m_instance == 0) {
        m_instance = new GFile;
    }
    return m_instance;
}
//===============================================
void GFile::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
// ifstream
//===============================================
void GFile::createIfstream(std::string fileId, std::string filename) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::ifstream* lFile = new std::ifstream(filename.c_str(), std::ifstream::in);
    m_ifstreamMap[fileId] = lFile;
}
//===============================================
void GFile::showData(std::string fileId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::ifstream* lFile = m_ifstreamMap[fileId];
    std::string lLine;
    while(getline(*lFile, lLine)) {
        std::cout << lLine << "\n";
    }
}
//===============================================
std::vector<std::vector<std::string>> GFile::getData(std::string fileId, char sep) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::ifstream* lFile = m_ifstreamMap[fileId];
    std::string lLine;
    std::vector<std::vector<std::string>> lStringsMap;
    while(getline(*lFile, lLine)) {
        lLine = GString::Instance()->trim(lLine);
        if(lLine == "") continue;
        std::vector<std::string> lStringMap = GString::Instance()->split(lLine, ';');
        lStringsMap.push_back(lStringMap);
    }
    return lStringsMap;
}
//===============================================
void GFile::deleteIfstream(std::string fileId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::ifstream* lFile = m_ifstreamMap[fileId];
    delete lFile;
    m_ifstreamMap[fileId] = 0;
}
//===============================================
