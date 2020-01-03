//===============================================
#ifndef _GModule_
#define _GModule_
//===============================================
#include "GInclude.h"
//===============================================
class GModule : public QWidget {
public:
	GModule(QWidget* parent = 0);
	~GModule();
	static GModule* Create(QString key);
};
//===============================================
#endif
//===============================================
