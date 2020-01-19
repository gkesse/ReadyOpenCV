//===============================================
#include "GMenuDefault.h"
#include "GPicto.h"
//===============================================
GMenuDefault::GMenuDefault(QWidget* parent) :
GMenu(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	QToolButton* lAddModule = new QToolButton;
	lAddModule->setObjectName("GToolButton");
	lAddModule->setToolTip(tr("Ajouter un module"));
	lAddModule->setCursor(Qt::PointingHandCursor);
	lAddModule->setIcon(GPicto::Instance()->getPicto(fa::plus));
	lAddModule->setIconSize(QSize(20, 20));

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(lAddModule);

	setLayout(lMainLayout);

	m_addModuleMenu = new QMenu(this);
	m_addModuleMenu->setCursor(Qt::PointingHandCursor);

	QAction* lAction;

	lAction = new QAction(this);
	lAction->setText(tr("Image"));
	lAction->setIcon(GPicto::Instance()->getPicto(fa::pictureo));
	m_addModuleMenu->addAction(lAction);
	m_moduleMap[lAction] = "IMAGE";

	lAction = new QAction(this);
	lAction->setText(tr("Video"));
	lAction->setIcon(GPicto::Instance()->getPicto(fa::videocamera));
	m_addModuleMenu->addAction(lAction);
	m_moduleMap[lAction] = "VIDEO";

	connect(lAddModule, SIGNAL(clicked()), this, SLOT(slotAddModuleMenuOpen()));
	connect(m_addModuleMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotAddModuleMenuSelect(QAction*)));
}
//===============================================
GMenuDefault::~GMenuDefault() {

}
//===============================================
