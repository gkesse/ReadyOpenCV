//===============================================
#ifndef _GSetting_
#define _GSetting_
//===============================================
#include "GInclude.h"
//===============================================
class GSetting {
private:
	GSetting();

public:
	~GSetting();
	static GSetting* Instance();
	void load();
	void save();
	void test();

private:
	static GSetting* m_instance;
	QString m_filename;
	QSettings* m_setting;

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
