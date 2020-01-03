//===============================================
#ifndef _GTitle_
#define _GTitle_
//===============================================
#include "GInclude.h"
//===============================================
class GTitle : public QWidget {
public:
	GTitle(QWidget* parent = 0);
	~GTitle();
	static GTitle* Create(QString key);
};
//===============================================
#endif
//===============================================
