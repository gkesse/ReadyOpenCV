//===============================================
#ifndef _GWorkspace_
#define _GWorkspace_
//===============================================
#include "GInclude.h"
//===============================================
class GWorkspace : public QFrame {
public:
	GWorkspace(QWidget* parent = 0);
	virtual ~GWorkspace();
	static GWorkspace* Create(QString key);
};
//===============================================
#endif
//===============================================
