//===============================================
#include "GModuleVideo.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
GModuleVideo::GModuleVideo(QWidget* parent) :
GModule(parent) {
	__CLASSNAME__ = __FUNCTION__;
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	m_title = new QLabel("Video");
	m_title->setObjectName("title");
	m_title->setAlignment(Qt::AlignCenter);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(m_title);

	setLayout(lMainLayout);

	QCheckBox* lCheck = new QCheckBox(m_title);
	lCheck->setToolTip(tr("Sélectionner/Désélectionner"));
	lCheck->setCursor(Qt::PointingHandCursor);
	lCheck->move(2, 2);

	QToolButton* lSetting = new QToolButton(m_title);
	int lSettingSize = 14;
	lSetting->setObjectName("GToolButton4");
	lSetting->setToolTip(tr("Ouvrir le menu"));
	lSetting->setCursor(Qt::PointingHandCursor);
	lSetting->setIcon(GPicto::Instance()->getPicto(fa::plus));
	lSetting->setIconSize(QSize(lSettingSize, lSettingSize));
	lSetting->move(50 - lSettingSize - 2, 0);

	m_moduleIndex = new QLabel(m_title);
	m_moduleIndex->setAlignment(Qt::AlignCenter);
	m_moduleIndex->setObjectName("GLabel3");
	m_moduleIndex->setText("1");
	m_moduleIndex->setGeometry(0, 50 - 15, 50, 15);

	setToolTip(tr("Module Video"));

	connect(lCheck, SIGNAL(clicked(bool)), this, SLOT(slotModuleCheck(bool)));
	connect(lSetting, SIGNAL(clicked()), this, SLOT(slotModuleSetting()));

	m_moduleMenu = new QMenu(this);
	m_moduleMenu->setCursor(Qt::PointingHandCursor);

	QAction* lAction;

	lAction = new QAction(this);
	m_actionMap[lAction] = "VIDEO_OPEN";
	lAction->setText(tr("Ouvrir une video"));
	lAction->setIcon(GPicto::Instance()->getPicto(fa::folderopen));
	m_moduleMenu->addAction(lAction);

	lAction = new QAction(this);
	m_actionMap[lAction] = "VIDEO_SAVE";
	lAction->setText(tr("Enregistrer une video"));
	lAction->setIcon(GPicto::Instance()->getPicto(fa::save));
	m_moduleMenu->addAction(lAction);

	connect(m_moduleMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotModuleMenuSelect(QAction*)));

	setPropertyData("status", "UNCHECK");
}
//===============================================
GModuleVideo::~GModuleVideo() {

}
//===============================================
