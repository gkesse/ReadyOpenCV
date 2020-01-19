//===============================================
#include "GModule.h"
#include "GModuleImage.h"
#include "GModuleVideo.h"
//===============================================
GModule::GModule(QWidget* parent) :
QFrame(parent) {
	setObjectName("GModule");
	m_index = 0;
	m_moduleMenu = 0;
	m_title = 0;
}
//===============================================
GModule::~GModule() {

}
//===============================================
void GModule::mousePressEvent(QMouseEvent *event) {
	if(event->button() == Qt::LeftButton) {
		if(m_propertyMap["status"] == "CURRENT") return;
		if(m_propertyMap["status"] == "CURRENT_CHECK") return;
		emit emitModuleCurrent(this);
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
	m_index = index;
}
//===============================================
void GModule::setTitle(int index) {
	QString lTitle = tr("%1 %2").arg(m_title->text()).arg(index);
	setToolTip(lTitle);
}
//===============================================
int GModule::getIndex() {
	return m_index;
}
//===============================================
void GModule::setPropertyData(QString key, QString value) {
	setProperty(key.toStdString().c_str(), value);
	m_propertyMap[key] = value;
}
//===============================================
void GModule::initCurrentStatus() {
	if(m_propertyMap["status"] == "CHECK") {setPropertyData("status", "CHECK");}
	else if(m_propertyMap["status"] == "CURRENT_CHECK") {setPropertyData("status", "CHECK");}
	else {setPropertyData("status", "UNCHECK");}
	style()->unpolish(this);
	style()->polish(this);
}
//===============================================
void GModule::setCurrentStatus() {
	if(m_propertyMap["status"] == "CHECK") {setPropertyData("status", "CURRENT_CHECK");}
	else {setPropertyData("status", "CURRENT");}
	style()->unpolish(this);
	style()->polish(this);
}
//===============================================
void GModule::slotModuleCheck(bool check) {
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
	QPoint lCursorPos = QCursor::pos();
	m_moduleMenu->exec(lCursorPos);
}
//===============================================
void GModule::slotModuleMenuSelect(QAction* action) {
	QString lAction = m_actionMap[action];
	emit emitModuleMenuAction(lAction, this);
}
//===============================================
