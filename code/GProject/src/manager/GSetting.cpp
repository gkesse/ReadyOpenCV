//================================================
#include "GSetting.h"
#include "GString.h"
#include "GConfig.h"
//================================================
GSetting* GSetting::m_instance = 0;
//================================================
GSetting::GSetting() {

}
//================================================
GSetting::~GSetting() {

}
//================================================
GSetting* GSetting::Instance() {
    if(m_instance == 0) {
        m_instance = new GSetting;
    }
    return m_instance;
}
//================================================
void GSetting::load(const string& file) {
    ifstream lFile;
    lFile.open(file);
    string lLine;
    while(getline(lFile, lLine)) {
        string lTrim = GString::Instance()->trim(lLine);
        if(lTrim == "") continue;
        char lFirstChar = lTrim.at(0);
        if(lFirstChar == '#') continue;
        vector<string> lSplit = GString::Instance()->split(lTrim, "=");
        string lKey = GString::Instance()->trim(lSplit[0]);
        string lValue = GString::Instance()->trim(lSplit[1]);
        GConfig::Instance()->setData(lKey, lValue);
    }
    string lConfigShow = GConfig::Instance()->getData("CONFIG_SHOW");
    if(lConfigShow == "TRUE") GConfig::Instance()->show();
    lFile.close();
}
//================================================
