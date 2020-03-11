//===============================================
#include "GMenu.h"
#include "GMenuDefault.h"
#include "GDebug.h"
//===============================================
GMenu::GMenu(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
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
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QPoint lCursorPos = QCursor::pos();
	m_addModuleMenu->exec(lCursorPos);
}
//===============================================
void GMenu::slotSettingMenuOpen() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QPoint lCursorPos = QCursor::pos();
	m_settingMenu->exec(lCursorPos);
}
//===============================================
void GMenu::slotAddModuleMenuSelect(QAction* action) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lAction = m_moduleMap[action];
	emit emitAddModuleMenuSelect(lAction);
}
//===============================================
void GMenu::slotSettingMenuSelect(QAction* action) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lAction = m_settingMap[action];
	emit emitSettingMenuSelect(lAction);
}
//===============================================
