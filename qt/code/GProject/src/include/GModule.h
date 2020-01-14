//===============================================
#ifndef _GModule_
#define _GModule_
//===============================================
#include "GInclude.h"
//===============================================
class GModule : public QFrame {
	Q_OBJECT

public:
	GModule(QWidget* parent = 0);
	virtual ~GModule();
	static GModule* Create(QString key);

public slots:
	virtual void slotModuleMenuSelect(QAction* action);
};
//===============================================
#endif
//===============================================
