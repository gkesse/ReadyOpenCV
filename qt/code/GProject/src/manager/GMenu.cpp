//===============================================
#include "GMenu.h"
#include "GMenuDefault.h"
//===============================================
GMenu::GMenu(QWidget* parent) :
QFrame(parent) {
	setObjectName("GMenu");
	m_addModuleMenu = 0;
}
//===============================================
GMenu::~GMenu() {

}
//===============================================
GMenu* GMenu::Create(QString key) {
	if(key == "DEFAULT") return new GMenuDefault;
	return new GMenuDefault;
}
//===============================================
void GMenu::slotAddModuleMenuOpen() {
	QPoint lCursorPos = QCursor::pos();
	m_addModuleMenu->exec(lCursorPos);
}
//===============================================
void GMenu::slotAddModuleMenuSelect(QAction* action) {
	QString lModule = m_moduleMap[action];
	emit emitAddModuleMenuSelect(lModule);
}
//===============================================
