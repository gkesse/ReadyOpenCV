//===============================================
#ifndef _GMenu_
#define _GMenu_
//===============================================
#include "GInclude.h"
//===============================================
class GMenu : public QFrame {
public:
	GMenu(QWidget* parent = 0);
	virtual ~GMenu();
	static GMenu* Create(QString key);
};
//===============================================
#endif
//===============================================
