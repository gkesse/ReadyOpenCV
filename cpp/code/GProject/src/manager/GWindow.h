//================================================
#ifndef _GWindow_
#define _GWindow_
//================================================
#include "GInclude.h"
//================================================
class GWindow {
private:
	GWindow();
	
public:
	~GWindow();
	static GWindow* Instance();
	void show(const string& windowName, const int& flags);
	void destroy(const string& windowName);
	void destroyAll();

private:
	static GWindow* m_instance;
};
//================================================
#endif
//================================================
