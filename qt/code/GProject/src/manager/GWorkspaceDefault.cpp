//===============================================
#include "GWorkspaceDefault.h"
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

	connect(this, SIGNAL(emitModuleCurrent(int)), m_workspace, SLOT(setCurrentIndex(int)));
}
//===============================================
GWorkspaceDefault::~GWorkspaceDefault() {

}
//===============================================
