//===============================================
#ifndef _GMenu_
#define _GMenu_
//===============================================
#include "GInclude.h"
//===============================================
class GMenu : public QFrame {
	Q_OBJECT

public:
	GMenu(QWidget* parent = 0);
	virtual ~GMenu();
	static GMenu* Create(QString key);

public slots:
	virtual void slotAddModuleMenuOpen();
	virtual void slotAddModuleMenuSelect(QAction* action);

signals:
	void emitAddModuleMenuSelect(QString module);

protected:
	QMenu* m_addModuleMenu;
	QMap<QAction*, QString> m_moduleMap;
};
//===============================================
#endif
//===============================================
