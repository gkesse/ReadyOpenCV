//===============================================
#include "GWorkspace.h"
#include "GWorkspaceDefault.h"
#include "GWorkspaceItem.h"
#include "GManager.h"
//===============================================
GWorkspace::GWorkspace(QWidget* parent) :
QFrame(parent) {
	setObjectName("GWorkspace");
	m_workspace = 0;
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
void GWorkspace::slotAddModuleMenuSelect(QString module) {
	if(GManager::Instance()->checkModuleMax() == true) return;
	GManager::Instance()->incrementModuleCount();
	int lIndex = GManager::Instance()->incrementModuleIndex();
	GWorkspaceItem* lWorkspace = GWorkspaceItem::Create(module);
	m_workspace->addWidget(lWorkspace);
	emit emitAddModuleMenuSelect(module, lIndex);
}
//===============================================
