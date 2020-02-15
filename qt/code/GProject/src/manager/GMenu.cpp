//===============================================
#include "GMenu.h"
#include "GMenuDefault.h"
//===============================================
GMenu::GMenu(QWidget* parent) :
QFrame(parent) {
	setObjectName("GMenu");
	m_addModuleMenu = 0;
	m_settingMenu = 0;
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
void GMenu::slotSettingMenuOpen() {
	QPoint lCursorPos = QCursor::pos();
	m_settingMenu->exec(lCursorPos);
}
//===============================================
void GMenu::slotAddModuleMenuSelect(QAction* action) {
	QString lAction = m_moduleMap[action];
	emit emitAddModuleMenuSelect(lAction);
}
//===============================================
void GMenu::slotSettingMenuSelect(QAction* action) {
	QString lAction = m_settingMap[action];
	emit emitSettingMenuSelect(lAction);
}
//===============================================
