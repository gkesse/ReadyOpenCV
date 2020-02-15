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

	QToolButton* lSetting = new QToolButton;
	lSetting->setObjectName("GToolButton");
	lSetting->setToolTip(tr("Accéder aux paramètres"));
	lSetting->setCursor(Qt::PointingHandCursor);
	lSetting->setIcon(GPicto::Instance()->getPicto(fa::cogs));
	lSetting->setIconSize(QSize(20, 20));

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(lAddModule);
	lMainLayout->addWidget(lSetting);

	setLayout(lMainLayout);

	createAddModuleMenu();
	createSettingMenu();

	connect(lAddModule, SIGNAL(clicked()), this, SLOT(slotAddModuleMenuOpen()));
	connect(lSetting, SIGNAL(clicked()), this, SLOT(slotSettingMenuOpen()));
}
//===============================================
GMenuDefault::~GMenuDefault() {

}
//===============================================
void GMenuDefault::createAddModuleMenu() {
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

	connect(m_addModuleMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotAddModuleMenuSelect(QAction*)));
}
//===============================================
void GMenuDefault::createSettingMenu() {
	m_settingMenu = new QMenu(this);
	m_settingMenu->setCursor(Qt::PointingHandCursor);

	QAction* lAction;

	lAction = new QAction(this);
	lAction->setText(tr("Afficher le manager"));
	lAction->setIcon(GPicto::Instance()->getPicto(fa::eyedropper));
	m_settingMenu->addAction(lAction);
	m_settingMap[lAction] = "MANAGER_PRINT";

	lAction = new QAction(this);
	lAction->setText(tr("Vider le manager"));
	lAction->setIcon(GPicto::Instance()->getPicto(fa::trash));
	m_settingMenu->addAction(lAction);
	m_settingMap[lAction] = "MANAGER_CLEAR";

	connect(m_settingMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotSettingMenuSelect(QAction*)));
}
//===============================================
