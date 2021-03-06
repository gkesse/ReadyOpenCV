//===============================================
#include "GSection.h"
#include "GSectionDefault.h"
#include "GManager.h"
#include "GDebug.h"
//===============================================
GSection::GSection(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GSection");
	m_scrollArea = 0;
	m_scrollLayout = 0;
	m_scrollWidget = 0;
	m_timer = 0;
}
//===============================================
GSection::~GSection() {

}
//===============================================
GSection* GSection::Create(QString key) {
	if(key == "DEFAULT") return new GSectionDefault;
	return new GSectionDefault;
}
//===============================================
bool GSection::eventFilter(QObject *object, QEvent *event) {
	//GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if (event->type() == QEvent::Resize) {
		if(object == m_scrollWidget || object == m_scrollArea->verticalScrollBar()) {
			m_timer->start();
		}
	}
	return QWidget::eventFilter(object, event);
}
//===============================================
void GSection::slotAddModuleMenuSelect(QString module) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(GManager::Instance()->checkModuleMax() == true) return;
	GManager::Instance()->incrementModuleCount();
	int lIndex = GManager::Instance()->incrementModuleIndex();
	GModule* lModule = GModule::Create(module);
	lModule->setIndex(lIndex);
	lModule->setTitle(lIndex);
	lModule->setModuleIndex(lIndex);
	m_scrollLayout->addWidget(lModule);
	m_moduleMap.append(lModule);
	connect(lModule, SIGNAL(emitModuleMenuAction(QString, int)), this, SIGNAL(emitModuleMenuAction(QString, int)));
	connect(lModule, SIGNAL(emitModuleCurrent(int)), this, SLOT(slotModuleCurrent(int)));
	connect(lModule, SIGNAL(emitModuleCurrent(int)), this, SIGNAL(emitModuleCurrent(int)));
	emit emitAddModuleMenuSelect(module, lIndex);
}
//===============================================
void GSection::slotAddModuleMenuTimer() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	int lWidth = 0;
	lWidth += m_scrollWidget->sizeHint().width();
	if(m_scrollArea->verticalScrollBar()->isVisible() == true) {
		lWidth += m_scrollArea->verticalScrollBar()->sizeHint().width();
	}
	m_scrollArea->setMinimumWidth(lWidth);
}
//===============================================
void GSection::slotModuleCurrent(int index) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	for(int i = 0; i < m_moduleMap.size(); i++) {
		GModule* lModule = m_moduleMap.at(i);
		lModule->initCurrentStatus();
		if(index == lModule->getIndex()) {
			lModule->setCurrentStatus();
		}
	}
}
//===============================================
