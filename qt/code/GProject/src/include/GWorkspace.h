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
	virtual void slotImageOpen(int index, QString action);
	virtual void slotSetImage(QString actionId);
	virtual void slotSetModuleIndex(int moduleIndex);

signals:
	void emitModuleCurrent(int index);

protected:
	QStackedWidget* m_workspace;
	int m_moduleIndex;

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
