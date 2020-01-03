//===============================================
#include "GWindowDefault.h"
#include "GTitle.h"
//===============================================
GWindowDefault::GWindowDefault(QWidget* parent) :
GWindow(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;
	QHBoxLayout* lCenterLayout = new QHBoxLayout;

	GTitle* lTitle = GTitle::Create("DEFAULT");
	QLabel* lMenu = new QLabel("Menu");
	QLabel* lWorkspace = new QLabel("Workspace");
	QLabel* lSection = new QLabel("Section");
	QLabel* lStatusBar = new QLabel("StatusBar");

	lCenterLayout->setMargin(0);
	lCenterLayout->setSpacing(0);
	lCenterLayout->addWidget(lMenu);
	lCenterLayout->addWidget(lWorkspace, 1);
	lCenterLayout->addWidget(lSection);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(lTitle);
	lMainLayout->addLayout(lCenterLayout, 1);
	lMainLayout->addWidget(lStatusBar);

	setLayout(lMainLayout);
}
//===============================================
GWindowDefault::~GWindowDefault() {

}
//===============================================
