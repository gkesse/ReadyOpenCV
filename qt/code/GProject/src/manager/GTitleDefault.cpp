//===============================================
#include "GTitleDefault.h"
#include "GPicto.h"
#include "GPrint.h"
//===============================================
GTitleDefault::GTitleDefault(QWidget* parent) :
GTitle(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	m_icon = new QToolButton;
	m_icon->setObjectName("GToolButton4");
	m_icon->setCursor(Qt::ArrowCursor);
	m_icon->setIconSize(QSize(30, 30));

	m_title = new QLabel(tr("TITRE"));
	m_title->setObjectName("GLabel");

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
void GTitleDefault::slotWindowTitleChange(QString title) {
	m_title->setText(title);
}
//===============================================
void GTitleDefault::slotWindowIconChange(QIcon icon) {
	m_icon->setIcon(icon);
}
//===============================================
void GTitleDefault::slotWindowMaximize(int oldState, int newState) {
	Q_UNUSED(newState)
			if(oldState == Qt::WindowMaximized) {
				m_maximize->setIcon(GPicto::Instance()->getPicto(fa::windowmaximize));
			}
			else if(oldState == Qt::WindowFullScreen) {
				m_maximize->setIcon(GPicto::Instance()->getPicto(fa::windowmaximize));
			}
			else {
				m_maximize->setIcon(GPicto::Instance()->getPicto(fa::windowrestore));
			}
}
//===============================================
void GTitleDefault::slotWindowFullScreen(int oldState, int newState) {
	if(oldState == Qt::WindowFullScreen) {
		if(newState == Qt::WindowMaximized) {
			m_maximize->setIcon(GPicto::Instance()->getPicto(fa::windowrestore));
		}
		else {
			m_maximize->setIcon(GPicto::Instance()->getPicto(fa::windowmaximize));
		}
	}
	else {
		m_maximize->setIcon(GPicto::Instance()->getPicto(fa::windowrestore));
	}
}
//===============================================
