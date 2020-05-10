//================================================
#ifndef _GDebug_
#define _GDebug_
//================================================
#include "GInclude.h"
//================================================
#define _EOA_ "_END_OF_ARG_"
//================================================
class GDebug {
private:
	GDebug();

public:
	~GDebug();
	static GDebug* Instance();
	void test(int argc, char** argv);
	void write(const char* key, ...);
	void sep();

private:
	void line(const char* data);
	void log(const char* data);
	void clear();
	void date(char* buffer);
#if defined(__WIN32)
	void homePathWin();
#elif defined(__unix)
	void homePathUnix();
#endif

private:
	const char* __CLASSNAME__;
	static GDebug* m_instance;
	char m_homePath[256];
	char m_debugPath[256];
	char m_filename[256];
};
//================================================
#endif
//================================================
