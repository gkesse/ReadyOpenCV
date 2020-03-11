//===============================================
#include "GWorkspaceDefault.h"
#include "GManager.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
GWorkspaceDefault::GWorkspaceDefault(QWidget* parent) :
GWorkspace(parent) {
	__CLASSNAME__ = __FUNCTION__;
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
	connect(this, SIGNAL(emitModuleCurrent(int)), this, SLOT(slotSetModuleIndex(int)));
}
//===============================================
GWorkspaceDefault::~GWorkspaceDefault() {

}
//===============================================
