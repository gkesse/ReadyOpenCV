//===============================================
#ifndef _GMenuDefault_
#define _GMenuDefault_
//===============================================
#include "GMenu.h"
//===============================================
class GMenuDefault : public GMenu {
public:
	GMenuDefault(QWidget* parent = 0);
	~GMenuDefault();

public slots:
	void slotAddModuleMenuOpen();
	void slotAddModuleMenuSelect(QAction* action);

private:
	QMenu* m_addModuleMenu;
	QMap<QAction*, QString> m_moduleMap;
};
//===============================================
#endif
//===============================================
