//===============================================
#ifndef _GMenu_
#define _GMenu_
//===============================================
#include "GInclude.h"
//===============================================
class GMenu : public QWidget {
public:
	GMenu(QWidget* parent = 0);
	~GMenu();
	static GMenu* Create(QString key);
};
//===============================================
#endif
//===============================================
