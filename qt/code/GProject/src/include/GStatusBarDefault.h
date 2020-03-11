//===============================================
#ifndef _GStatusBarDefault_
#define _GStatusBarDefault_
//===============================================
#include "GStatusBar.h"
//===============================================
class GStatusBarDefault : public GStatusBar {
public:
	GStatusBarDefault(QWidget* parent = 0);
	~GStatusBarDefault();

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
