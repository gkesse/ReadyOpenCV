//===============================================
#include "GModule.h"
#include "GModuleImage.h"
#include "GModuleVideo.h"
#include "GManager.h"
#include "GDebug.h"
//===============================================
GModule::GModule(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GModule");
	m_index = 0;
	m_moduleMenu = 0;
	m_moduleIndex = 0;
	m_title = 0;
}
//===============================================
GModule::~GModule() {

}
//===============================================
void GModule::mousePressEvent(QMouseEvent *event) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(event->button() == Qt::LeftButton) {
		GManager::Instance()->setModuleCurrentIndex(m_index);
		if(m_propertyMap["status"] == "CURRENT") return;
		if(m_propertyMap["status"] == "CURRENT_CHECK") return;
		emit emitModuleCurrent(m_index);
	}
	QWidget::mousePressEvent(event);
}
//===============================================
GModule* GModule::Create(QString key) {
	if(key == "IMAGE") return new GModuleImage;
	if(key == "VIDEO") return new GModuleVideo;
	return new GModuleImage;
}
//===============================================
void GModule::setIndex(int index) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	m_index = index;
}
//===============================================
void GModule::setTitle(int index) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lTitle = tr("%1 %2").arg(m_title->text()).arg(index);
	setToolTip(lTitle);
}
//===============================================
int GModule::getIndex() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	return m_index;
}
//===============================================
void GModule::setPropertyData(QString key, QString value) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	setProperty(key.toStdString().c_str(), value);
	m_propertyMap[key] = value;
}
//===============================================
void GModule::initCurrentStatus() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(m_propertyMap["status"] == "CHECK") {setPropertyData("status", "CHECK");}
	else if(m_propertyMap["status"] == "CURRENT_CHECK") {setPropertyData("status", "CHECK");}
	else {setPropertyData("status", "UNCHECK");}
	style()->unpolish(this);
	style()->polish(this);
}
//===============================================
void GModule::setCurrentStatus() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(m_propertyMap["status"] == "CHECK") {setPropertyData("status", "CURRENT_CHECK");}
	else {setPropertyData("status", "CURRENT");}
	style()->unpolish(this);
	style()->polish(this);
}
//===============================================
void GModule::setModuleIndex(int moduleIdenx) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lModuleIndex = QString("%1").arg(moduleIdenx);
	m_moduleIndex->setText(lModuleIndex);
}
//===============================================
void GModule::slotModuleCheck(bool check) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(check == true) {
		if(m_propertyMap["status"] == "CURRENT") {setPropertyData("status", "CURRENT_CHECK");}
		else {setPropertyData("status", "CHECK");}
	}
	else {
		if(m_propertyMap["status"] == "CURRENT_CHECK") {setPropertyData("status", "CURRENT");}
		else {setPropertyData("status", "UNCHECK");}
	}
	style()->unpolish(this);
	style()->polish(this);
}
//===============================================
void GModule::slotModuleSetting() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	int lCurrentIndex = GManager::Instance()->getModuleCurrentIndex();
	GDebug::Instance()->write(3, "MODULE_INDEX : ", 1, m_index, 3, " : ", 3, m_moduleIndex->text().toStdString().c_str(), 3, " : ",1, lCurrentIndex, 0);
	if(lCurrentIndex != m_index) return;
	QPoint lCursorPos = QCursor::pos();
	m_moduleMenu->exec(lCursorPos);
}
//===============================================
void GModule::slotModuleMenuSelect(QAction* action) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lAction = m_actionMap[action];
	emit emitModuleMenuAction(lAction, m_index);
}
//===============================================
