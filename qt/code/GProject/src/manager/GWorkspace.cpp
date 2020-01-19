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
void GWorkspace::slotAddModuleMenuSelect(QString module, int index) {
	GWorkspaceItem* lWorkspace = GWorkspaceItem::Create(module);
	lWorkspace->setTitle(index);
	m_workspace->addWidget(lWorkspace);
}
//===============================================
void GWorkspace::slotImageOpen(QString filename, GModule* module) {
	int lIndex = module->getIndex();
	GWorkspaceItem* lWorkspace = qobject_cast<GWorkspaceItem*>(m_workspace->widget(lIndex));
	lWorkspace->setImage(filename);
	m_workspace->setCurrentIndex(lIndex);
	emit emitModuleCurrent(module);
}
//===============================================
