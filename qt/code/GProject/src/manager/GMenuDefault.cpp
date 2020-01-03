//===============================================
#include "GMenuDefault.h"
#include "GPicto.h"
//===============================================
GMenuDefault::GMenuDefault(QWidget* parent) :
GMenu(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	QToolButton* lAddModule = new QToolButton;
	lAddModule->setObjectName("add_module");
	lAddModule->setToolTip(tr("Ajouter un module"));
	lAddModule->setCursor(Qt::PointingHandCursor);
	lAddModule->setIcon(GPicto::Instance()->getPicto(fa::plus));
	lAddModule->setIconSize(QSize(20, 20));


	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(lAddModule);

	setLayout(lMainLayout);
}
//===============================================
GMenuDefault::~GMenuDefault() {

}
//===============================================
