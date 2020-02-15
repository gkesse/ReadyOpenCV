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
	virtual void slotSettingMenuOpen();
	virtual void slotAddModuleMenuSelect(QAction* action);
	virtual void slotSettingMenuSelect(QAction* action);

signals:
	void emitAddModuleMenuSelect(QString module);
	void emitSettingMenuSelect(QString module);

protected:
	QMenu* m_addModuleMenu;
	QMenu* m_settingMenu;
	QMap<QAction*, QString> m_moduleMap;
	QMap<QAction*, QString> m_settingMap;
};
//===============================================
#endif
//===============================================
