//===============================================
#include "GTitleDefault.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
GTitleDefault::GTitleDefault(QWidget* parent) :
GTitle(parent) {
	__CLASSNAME__ = __FUNCTION__;
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	m_icon = new QToolButton;
	m_icon->setObjectName("GIcon");
	m_icon->setCursor(Qt::ArrowCursor);
	m_icon->setIconSize(QSize(30, 30));

	m_title = new QLabel(tr("TITRE"));
	m_title->setObjectName("GTitle2");

	QToolButton* lMinimize = new QToolButton;
	lMinimize->setObjectName("GToolButton");
	lMinimize->setCursor(Qt::PointingHandCursor);
	lMinimize->setIcon(GPicto::Instance()->getPicto(fa::windowminimize));
	lMinimize->setIconSize(QSize(20, 20));

	m_maximize = new QToolButton;
	m_maximize->setObjectName("GToolButton");
	m_maximize->setCursor(Qt::PointingHandCursor);
	m_maximize->setIcon(GPicto::Instance()->getPicto(fa::windowmaximize));
	m_maximize->setIconSize(QSize(20, 20));

	QToolButton* lClose = new QToolButton;
	lClose->setObjectName("GToolButton2");
	lClose->setCursor(Qt::PointingHandCursor);
	lClose->setIcon(GPicto::Instance()->getPicto(fa::close));
	lClose->setIconSize(QSize(20, 20));

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(m_icon);
	lMainLayout->addWidget(m_title, 1);
	lMainLayout->addWidget(lMinimize);
	lMainLayout->addWidget(m_maximize);
	lMainLayout->addWidget(lClose);

	setLayout(lMainLayout);

	connect(lMinimize, SIGNAL(clicked()), this, SIGNAL(emitWindowMinimize()));
	connect(m_maximize, SIGNAL(clicked()), this, SIGNAL(emitWindowMaximize()));
	connect(lClose, SIGNAL(clicked()), this, SIGNAL(emitWindowClose()));
}
//===============================================
GTitleDefault::~GTitleDefault() {

}
//===============================================
