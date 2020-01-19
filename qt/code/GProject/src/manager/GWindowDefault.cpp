//===============================================
#include "GWindowDefault.h"
#include "GTitle.h"
#include "GMenu.h"
#include "GWorkspace.h"
#include "GSection.h"
#include "GStatusBar.h"
#include "GPicto.h"
#include "GManager.h"
//===============================================
GWindowDefault::GWindowDefault(QWidget* parent) :
GWindow(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;
	QHBoxLayout* lCenterLayout = new QHBoxLayout;

	GTitle* lTitle = GTitle::Create("DEFAULT");
	GMenu* lMenu = GMenu::Create("DEFAULT");
	GWorkspace* lWorkspace = GWorkspace::Create("DEFAULT");
	GSection* lSection = GSection::Create("DEFAULT");
	GStatusBar* lStatusBar = GStatusBar::Create("DEFAULT");
	GManager* lManager = GManager::Instance();

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

	setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
	setAttribute(Qt::WA_TranslucentBackground);

	connect(lTitle, SIGNAL(emitWindowPress(QPoint)), this, SLOT(slotWindowPress(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMove(QPoint)), this, SLOT(slotWindowMove(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMinimize()), this, SLOT(slotWindowMinimize()));
	connect(lTitle, SIGNAL(emitWindowMaximize()), this, SLOT(slotWindowMaximize()));
	connect(lTitle, SIGNAL(emitWindowClose()), this, SLOT(close()));
	connect(lTitle, SIGNAL(emitWindowFullScreen()), this, SLOT(slotWindowFullScreen()));

	connect(lMenu, SIGNAL(emitAddModuleMenuSelect(QString)), lSection, SLOT(slotAddModuleMenuSelect(QString)));

	connect(lSection, SIGNAL(emitAddModuleMenuSelect(QString, int)), lWorkspace, SLOT(slotAddModuleMenuSelect(QString, int)));
	connect(lSection, SIGNAL(emitModuleMenuAction(QString, GModule*)), this, SLOT(slotModuleMenuAction(QString, GModule*)));
	connect(lSection, SIGNAL(emitModuleCurrent(int)), lWorkspace, SIGNAL(emitModuleCurrent(int)));

	connect(lWorkspace, SIGNAL(emitModuleCurrent(GModule*)), lSection, SLOT(slotModuleCurrent(GModule*)));

	connect(lManager, SIGNAL(emitModuleMax()), this, SLOT(slotModuleMax()));
	connect(lManager, SIGNAL(emitImageOpen(QString, GModule*)), lWorkspace, SLOT(slotImageOpen(QString, GModule*)));

	connect(this, SIGNAL(windowTitleChanged(QString)), lTitle, SLOT(slotWindowTitleChange(QString)));
	connect(this, SIGNAL(windowIconChanged(QIcon)), lTitle, SLOT(slotWindowIconChange(QIcon)));
	connect(this, SIGNAL(emitWindowMaximize(int, int)), lTitle, SLOT(slotWindowMaximize(int, int)));
	connect(this, SIGNAL(emitWindowFullScreen(int, int)), lTitle, SLOT(slotWindowFullScreen(int, int)));

	setWindowTitle(tr("OpenCV | ReadyDev"));
	GPicto::Instance()->setColor("navy");
	setWindowIcon(GPicto::Instance()->getPicto(fa::snowflakeo));

	m_sizeGrip = new QSizeGrip(this);
}
//===============================================
GWindowDefault::~GWindowDefault() {

}
//===============================================
