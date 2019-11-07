//================================================
#include "GConfig.h"
//================================================
GConfig* GConfig::m_instance = 0;
//================================================
GConfig::GConfig() {

}
//================================================
GConfig::~GConfig() {
	
}
//================================================
GConfig* GConfig::Instance() {
	if(m_instance == 0) {
		m_instance = new GConfig;
	}
	return m_instance;
}
//================================================
void GConfig::setData(const string& key, const string& data) {
    m_dataMap[key] = data;
}
//================================================
string GConfig::getData(const string &key) {
    exist(key);
    return m_dataMap[key];
}
//===============================================
void GConfig::show() {
    for(map<string, string>::iterator item = m_dataMap.begin(); item != m_dataMap.end(); item++) {
        cout << item->first << " = " << item->second << "\n";
    }
    cout << "\n";
}
//================================================
void GConfig::exist(const string& key) {
    bool lExist = (m_dataMap.find(key) == m_dataMap.end()) ? false : true;
    if(lExist == false) {cout << "[ GConfig ] Error GConfig::exist: " << key << "\n"; exit(1);}
}
//===============================================
