//===============================================
#include "GWindowDefault.h"
#include "GTitle.h"
#include "GMenu.h"
#include "GWorkspace.h"
#include "GSection.h"
#include "GStatusBar.h"
#include "GPicto.h"
#include "GImage.h"
#include "GManager.h"
#include "GDebug.h"
//===============================================
GWindowDefault::GWindowDefault(QWidget* parent) :
GWindow(parent) {
	__CLASSNAME__ = __FUNCTION__;
	QVBoxLayout* lMainLayout = new QVBoxLayout;
	QHBoxLayout* lCenterLayout = new QHBoxLayout;

	GTitle* lTitle = GTitle::Create("DEFAULT");
	GMenu* lMenu = GMenu::Create("DEFAULT");
	GWorkspace* lWorkspace = GWorkspace::Create("DEFAULT");
	GSection* lSection = GSection::Create("DEFAULT");
	GStatusBar* lStatusBar = GStatusBar::Create("DEFAULT");
	GImage* lImage = GImage::Instance();
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

	connect(lTitle, SIGNAL(emitWindowPress(QPoint)), this, SLOT(slotWindowPress(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMove(QPoint)), this, SLOT(slotWindowMove(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMinimize()), this, SLOT(slotWindowMinimize()));
	connect(lTitle, SIGNAL(emitWindowMaximize()), this, SLOT(slotWindowMaximize()));
	connect(lTitle, SIGNAL(emitWindowClose()), this, SLOT(close()));
	connect(lTitle, SIGNAL(emitWindowFullScreen()), this, SLOT(slotWindowFullScreen()));

	connect(lMenu, SIGNAL(emitAddModuleMenuSelect(QString)), lSection, SLOT(slotAddModuleMenuSelect(QString)));
	connect(lMenu, SIGNAL(emitSettingMenuSelect(QString)), this, SLOT(slotSettingMenuSelect(QString)));

	connect(lSection, SIGNAL(emitAddModuleMenuSelect(QString, int)), lWorkspace, SLOT(slotAddModuleMenuSelect(QString, int)));
	connect(lSection, SIGNAL(emitModuleMenuAction(QString, int)), this, SLOT(slotModuleMenuAction(QString, int)));
	connect(lSection, SIGNAL(emitModuleCurrent(int)), lWorkspace, SIGNAL(emitModuleCurrent(int)));

	connect(lWorkspace, SIGNAL(emitModuleCurrent(int)), lSection, SLOT(slotModuleCurrent(int)));

	connect(lImage, SIGNAL(emitImageOpen(int, QString)), lWorkspace, SLOT(slotImageOpen(int, QString)));
	connect(lImage, SIGNAL(emitImageOpen(QString)), lWorkspace, SLOT(slotSetImage(QString)));

	connect(lManager, SIGNAL(emitModuleMax()), this, SLOT(slotModuleMax()));

	connect(this, SIGNAL(windowTitleChanged(QString)), lTitle, SLOT(slotWindowTitleChange(QString)));
	connect(this, SIGNAL(windowIconChanged(QIcon)), lTitle, SLOT(slotWindowIconChange(QIcon)));
	connect(this, SIGNAL(emitWindowMaximize(int, int)), lTitle, SLOT(slotWindowMaximize(int, int)));
	connect(this, SIGNAL(emitWindowFullScreen(int, int)), lTitle, SLOT(slotWindowFullScreen(int, int)));

	setWindowTitle(tr("Qt | ReadyDev"));
	GPicto::Instance()->setColor("orange");
	setWindowIcon(GPicto::Instance()->getPicto(fa::snowflakeo));

	m_sizeGrip = new QSizeGrip(this);

	m_pixmapBg.load(":/img/vision.png");
}
//===============================================
GWindowDefault::~GWindowDefault() {
	GManager::Instance()->save();
}
//===============================================
