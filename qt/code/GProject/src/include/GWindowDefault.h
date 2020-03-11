//===============================================
#ifndef _GWindowDefault_
#define _GWindowDefault_
//===============================================
#include "GWindow.h"
//===============================================
class GWindowDefault : public GWindow {
public:
	GWindowDefault(QWidget* parent = 0);
	~GWindowDefault();

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
