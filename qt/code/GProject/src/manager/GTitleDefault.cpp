//===============================================
#include "GTitleDefault.h"
#include "GPicto.h"
#include "GPrint.h"
//===============================================
GTitleDefault::GTitleDefault(QWidget* parent) :
GTitle(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	QToolButton* lIcon = new QToolButton;
	lIcon->setObjectName("icon");
	lIcon->setCursor(Qt::ArrowCursor);
	GPicto::Instance()->setColor("navy");
	lIcon->setIcon(GPicto::Instance()->getPicto(fa::snowflakeo));
	lIcon->setIconSize(QSize(30, 30));

	QLabel* lTitle = new QLabel("OpenCV | ReadyDev");
	lTitle->setObjectName("title");

	QToolButton* lMinimize = new QToolButton;
	lMinimize->setObjectName("minimize");
	lMinimize->setCursor(Qt::PointingHandCursor);
	lMinimize->setIcon(GPicto::Instance()->getPicto(fa::windowminimize));
	lMinimize->setIconSize(QSize(20, 20));

	m_maximize = new QToolButton;
	m_maximize->setObjectName("maximize");
	m_maximize->setCursor(Qt::PointingHandCursor);
	m_maximize->setIcon(GPicto::Instance()->getPicto(fa::windowmaximize));
	m_maximize->setIconSize(QSize(20, 20));

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
void GTitleDefault::mousePressEvent(QMouseEvent *event) {
	if(event->button() == Qt::LeftButton) {
		QPoint lPressPosition = event->globalPos();
		emit emitWindowPress(lPressPosition);
	}
	QWidget::mousePressEvent(event);
}
//===============================================
void GTitleDefault::mouseMoveEvent(QMouseEvent *event) {
	if(event->buttons() & Qt::LeftButton) {
		QPoint lMovePosition = event->globalPos();
		emit emitWindowMove(lMovePosition);
	}
	QWidget::mouseMoveEvent(event);
}
//===============================================
void GTitleDefault::mouseDoubleClickEvent(QMouseEvent *event) {
	if(event->button() == Qt::LeftButton) {
		emit emitWindowFullScreen();
	}
	QWidget::mouseDoubleClickEvent(event);
}
//===============================================
void GTitleDefault::slotWindowMaximize(int state) {
	if(state == Qt::WindowMaximized) {
		m_maximize->setIcon(GPicto::Instance()->getPicto(fa::windowmaximize));
	}
	else {
		m_maximize->setIcon(GPicto::Instance()->getPicto(fa::windowrestore));
	}
}
//===============================================
