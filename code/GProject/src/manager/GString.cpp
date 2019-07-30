//================================================
#include "GString.h"
//================================================
GString* GString::m_instance = 0;
//================================================
GString::GString() {

}
//================================================
GString::~GString() {
	
}
//================================================
GString* GString::Instance() {
	if(m_instance == 0) {
		m_instance = new GString;
	}
	return m_instance;
}
//================================================
string GString::trimLeft(const string& str, const string& chars) {
    string lTrim(str);
    lTrim.erase(0, lTrim.find_first_not_of(chars));
    return lTrim;
}
//================================================
string GString::trimRight(const string& str, const string& chars) {
    string lTrim(str);
    lTrim.erase(lTrim.find_last_not_of(chars) + 1);
    return lTrim;
}
//================================================
string GString::trim(const string& str, const string& chars) {
    return trimLeft(trimRight(str, chars), chars);
}
//================================================
vector<string> GString::split(const string& str, const string& delimiter) {
    size_t lPosStart = 0;
    size_t lPosEnd;
    size_t lDelimLen = delimiter.length();
    string lToken;
    vector<string> lSplit;

    while ((lPosEnd = str.find(delimiter, lPosStart)) != string::npos) {
        lToken = str.substr(lPosStart, lPosEnd - lPosStart);
        lPosStart = lPosEnd + lDelimLen;
        lSplit.push_back (lToken);
    }

    lSplit.push_back (str.substr (lPosStart));
    return lSplit;
}
//===============================================
