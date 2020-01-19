//===============================================
#ifndef _GWorkspace_
#define _GWorkspace_
//===============================================
#include "GInclude.h"
#include "GModule.h"
//===============================================
class GWorkspace : public QFrame {
	Q_OBJECT

public:
	GWorkspace(QWidget* parent = 0);
	virtual ~GWorkspace();
	static GWorkspace* Create(QString key);

public slots:
	virtual void slotAddModuleMenuSelect(QString module, int index);
	virtual void slotImageOpen(QString filename, GModule* module);

signals:
	void emitModuleCurrent(int index);
	void emitModuleCurrent(GModule* module);

protected:
	QStackedWidget* m_workspace;
};
//===============================================
#endif
//===============================================
