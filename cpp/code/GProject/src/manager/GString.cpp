//===============================================
#include "GString.h"
#include "GDebug.h"
//===============================================
GString* GString::m_instance = 0;
//===============================================
GString::GString() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GString::~GString() {

}
//===============================================
GString* GString::Instance() {
    if(m_instance == 0) {
        m_instance = new GString;
    }
    return m_instance;
}
//===============================================
void GString::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
// string
//===============================================
std::string GString::trim(std::string str) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    return ltrim(rtrim(str));
}
//===============================================
std::string GString::ltrim(std::string str) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::string lString = str;
    lString.erase(lString.begin(), std::find_if(lString.begin(), lString.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return lString;
}
//===============================================
std::string GString::rtrim(std::string str) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::string lString = str;
    lString.erase(std::find_if(lString.rbegin(), lString.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), lString.end());
    return lString;
}
//===============================================
std::vector<std::string> GString::split(std::string str, char sep) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    std::istringstream lStream(str);
    std::string lString;    
    std::vector<std::string> lStringMap;
    while(getline(lStream, lString, sep)) {
        lStringMap.push_back(lString);
    }
    return lStringMap;
}
//===============================================
std::string GString::getFilename(std::string path) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    if(path.empty()) {return {};}
    
    int lLength = path.length();
    int lIndex = path.find_last_of("/\\");
    
    if(lIndex == std::string::npos) {return path;}

    if (lIndex + 1 >= lLength) {
        lLength--;
        lIndex = path.substr(0, lLength).find_last_of("/\\");
        if (lLength == 0) {return path;}
        if (lIndex == 0) {return path.substr(1, lLength - 1);}
        if (lIndex == std::string::npos) {return path.substr(0, lLength);}
        return path.substr(lIndex + 1, lLength - lIndex - 1);
    }
    return path.substr(lIndex + 1, lLength - lIndex);
}
//===============================================
