//================================================
#ifndef _GConfig_
#define _GConfig_
//================================================
#include "GInclude.h"
//================================================
class GConfig {
private:
	GConfig();
	
public:
	~GConfig();
	static GConfig* Instance();
    void setData(const string &key, const string &data);
    string getData(const string& key);
    void show();
    void exist(const string& key);

private:
	static GConfig* m_instance;
    map<string, string> m_dataMap;
};
//================================================
#endif
//================================================
