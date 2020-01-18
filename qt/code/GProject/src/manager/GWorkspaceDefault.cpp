//===============================================
#include "GWorkspaceDefault.h"
#include "GWorkspaceItem.h"
#include "GManager.h"
#include "GPicto.h"
//===============================================
GWorkspaceDefault::GWorkspaceDefault(QWidget* parent) :
GWorkspace(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	m_workspace = new QStackedWidget;
	QLabel* lWorkspace = new QLabel(tr("Workspace"));
	lWorkspace->setAlignment(Qt::AlignCenter);
	m_workspace->addWidget(lWorkspace);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(m_workspace);

	setLayout(lMainLayout);
}
//===============================================
GWorkspaceDefault::~GWorkspaceDefault() {

}
//===============================================
void GWorkspaceDefault::slotAddModuleMenuSelect(QString module) {
	if(GManager::Instance()->checkModuleMax() == true) return;
	GManager::Instance()->incrementModuleCount();
	int lIndex = GManager::Instance()->incrementModuleIndex();
	GWorkspaceItem* lWorkspace = GWorkspaceItem::Create(module);
	m_workspace->addWidget(lWorkspace);
	m_workspace->setCurrentIndex(lIndex);
	emit emitAddModuleMenuSelect(module);
}
//===============================================
