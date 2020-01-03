//===============================================
#ifndef _GWorkspace_
#define _GWorkspace_
//===============================================
#include "GInclude.h"
//===============================================
class GWorkspace : public QWidget {
public:
	GWorkspace(QWidget* parent = 0);
	~GWorkspace();
	static GWorkspace* Create(QString key);
};
//===============================================
#endif
//===============================================
