//===============================================
#include "GWorkspace.h"
#include "GWorkspaceDefault.h"
#include "GWorkspaceItem.h"
#include "GManager.h"
#include "GDebug.h"
//===============================================
GWorkspace::GWorkspace(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWorkspace");
	m_workspace = 0;
	m_moduleIndex = 0;
}
//===============================================
GWorkspace::~GWorkspace() {

}
//===============================================
GWorkspace* GWorkspace::Create(QString key) {
	if(key == "DEFAULT") return new GWorkspaceDefault;
	return new GWorkspaceDefault;
}
//===============================================
void GWorkspace::slotAddModuleMenuSelect(QString module, int index) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	GWorkspaceItem* lWorkspaceItem = GWorkspaceItem::Create(module);
	lWorkspaceItem->setTitle(index);
	m_workspace->addWidget(lWorkspaceItem);
}
//===============================================
void GWorkspace::slotImageOpen(int index, QString action) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	GWorkspaceItem* lWorkspaceItem = qobject_cast<GWorkspaceItem*>(m_workspace->widget(index));
	lWorkspaceItem->setImage(index, action);
	m_workspace->setCurrentIndex(index);
	m_moduleIndex = index;
	GDebug::Instance()->write(3, "MODULE_INDEX : ", 1, m_moduleIndex, 0);
	emit emitModuleCurrent(index);
}
//===============================================
void GWorkspace::slotSetImage(QString actionId) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	GWorkspaceItem* lWorkspaceItem = qobject_cast<GWorkspaceItem*>(m_workspace->widget(m_moduleIndex));
	lWorkspaceItem->setImage(actionId);
}
//===============================================
void GWorkspace::slotSetModuleIndex(int moduleIndex) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	m_moduleIndex = moduleIndex;
	GDebug::Instance()->write(3, "MODULE_INDEX", 3, " : ", 1, m_moduleIndex, 0);
	GWorkspaceItem* lWorkspaceItem = qobject_cast<GWorkspaceItem*>(m_workspace->widget(m_moduleIndex));
	lWorkspaceItem->setActionId();
}
//===============================================
