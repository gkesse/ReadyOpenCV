//================================================
#ifndef _GConsole_
#define _GConsole_
//================================================
#include "GInclude.h"
//================================================
class GConsole {
private:
	GConsole();
	
public:
	~GConsole();
	static GConsole* Instance();
    void print(const string &data);

private:
	static GConsole* m_instance;
};
//================================================
#endif
//================================================
