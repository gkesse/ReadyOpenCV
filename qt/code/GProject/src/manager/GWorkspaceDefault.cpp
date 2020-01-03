//===============================================
#include "GWorkspaceDefault.h"
#include "GPicto.h"
//===============================================
GWorkspaceDefault::GWorkspaceDefault(QWidget* parent) :
GWorkspace(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	QToolButton* lIcon = new QToolButton;
	lIcon->setObjectName("icon");
	lIcon->setCursor(Qt::ArrowCursor);
	GPicto::Instance()->setColor("orange");
	lIcon->setIcon(GPicto::Instance()->getPicto(fa::snowflakeo));
	lIcon->setIconSize(QSize(30, 30));

	QLabel* lTitle = new QLabel("OpenCV | ReadyDev");
	lTitle->setObjectName("title");

	QToolButton* lMinimize = new QToolButton;
	lMinimize->setObjectName("minimize");
	lMinimize->setCursor(Qt::PointingHandCursor);
	lMinimize->setIcon(GPicto::Instance()->getPicto(fa::windowminimize));
	lMinimize->setIconSize(QSize(20, 20));

	QToolButton* lMaximize = new QToolButton;
	lMaximize->setObjectName("maximize");
	lMaximize->setCursor(Qt::PointingHandCursor);
	lMaximize->setIcon(GPicto::Instance()->getPicto(fa::windowmaximize));
	lMaximize->setIconSize(QSize(20, 20));

	QToolButton* lClose = new QToolButton;
	lClose->setObjectName("close");
	lClose->setCursor(Qt::PointingHandCursor);
	lClose->setIcon(GPicto::Instance()->getPicto(fa::close));
	lClose->setIconSize(QSize(20, 20));

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(lIcon);
	lMainLayout->addWidget(lTitle, 1);
	lMainLayout->addWidget(lMinimize);
	lMainLayout->addWidget(lMaximize);
	lMainLayout->addWidget(lClose);

	setLayout(lMainLayout);
}
//===============================================
GWorkspaceDefault::~GWorkspaceDefault() {

}
//===============================================
