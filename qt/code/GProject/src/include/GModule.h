//===============================================
#ifndef _GModule_
#define _GModule_
//===============================================
#include "GInclude.h"
//===============================================
class GModule : public QFrame {
public:
	GModule(QWidget* parent = 0);
	virtual ~GModule();
	static GModule* Create(QString key);
};
//===============================================
#endif
//===============================================
