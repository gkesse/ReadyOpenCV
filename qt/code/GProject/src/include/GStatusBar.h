//===============================================
#ifndef _GStatusBar_
#define _GStatusBar_
//===============================================
#include "GInclude.h"
//===============================================
class GStatusBar : public QWidget {
public:
	GStatusBar(QWidget* parent = 0);
	~GStatusBar();
	static GStatusBar* Create(QString key);
};
//===============================================
#endif
//===============================================
