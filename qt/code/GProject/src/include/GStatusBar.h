//===============================================
#ifndef _GStatusBar_
#define _GStatusBar_
//===============================================
#include "GInclude.h"
//===============================================
class GStatusBar : public QFrame {
public:
	GStatusBar(QWidget* parent = 0);
	virtual ~GStatusBar();
	static GStatusBar* Create(QString key);
};
//===============================================
#endif
//===============================================
