//===============================================
#include "GWorkspaceDefault.h"
#include "GPicto.h"
//===============================================
GWorkspaceDefault::GWorkspaceDefault(QWidget* parent) :
GWorkspace(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	QLabel* lWorkspace = new QLabel(tr("Workspace"));
	lWorkspace->setObjectName("workspace");
	lWorkspace->setAlignment(Qt::AlignCenter);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(lWorkspace);

	setLayout(lMainLayout);
}
//===============================================
GWorkspaceDefault::~GWorkspaceDefault() {

}
//===============================================
