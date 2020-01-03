//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include "GInclude.h"
//===============================================
class GWindow : public QWidget {
public:
	GWindow(QWidget* parent = 0);
	~GWindow();
	static GWindow* Create(QString key);
};
//===============================================
#endif
//===============================================
