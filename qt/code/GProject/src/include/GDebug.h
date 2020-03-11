//===============================================
#ifndef _GDebug_
#define _GDebug_
//===============================================
#include "GInclude.h"
//===============================================
class GDebug {
private:
	GDebug();

public:
	~GDebug();
	static GDebug* Instance();
	void clear();
	void getCurrentDate();
	void write(const char* format, ...);
	void write(int format, ...);

private:
	static GDebug* m_instance;
	string m_filename;
	char m_date[G_BUFFER_STRING];

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
