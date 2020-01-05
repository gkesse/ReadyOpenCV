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
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(lAddModule);

	setLayout(lMainLayout);

	m_addModuleMenu = new QMenu(this);
	m_addModuleMenu->setObjectName("add_menu");

	QAction* lAction;

	lAction = new QAction(this);
	lAction->setText(tr("Image"));
	lAction->setIcon(GPicto::Instance()->getPicto(fa::pictureo));
	m_addModuleMenu->addAction(lAction);
	m_moduleMap[lAction] = "IMAGE";

	connect(lAddModule, SIGNAL(clicked()), this, SLOT(slotAddModuleMenuOpen()));
	connect(m_addModuleMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotAddModuleMenuSelect(QAction*)));
}
//===============================================
GMenuDefault::~GMenuDefault() {

}
//===============================================
void GMenuDefault::slotAddModuleMenuOpen() {
	QPoint lCursorPos = QCursor::pos();
	m_addModuleMenu->exec(lCursorPos);
}
//===============================================
void GMenuDefault::slotAddModuleMenuSelect(QAction* action) {

}
//===============================================
