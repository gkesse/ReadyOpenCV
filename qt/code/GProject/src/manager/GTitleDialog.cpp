//===============================================
#include "GTitleDialog.h"
#include "GPicto.h"
#include "GPrint.h"
#include "GDebug.h"
//===============================================
GTitleDialog::GTitleDialog(QWidget* parent) :
GTitle(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GTitle2");
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	m_icon = new QToolButton;
	m_icon->setCursor(Qt::ArrowCursor);
	m_icon->setIconSize(QSize(30, 30));

	m_title = new QLabel(tr("TITRE"));
	m_title->setObjectName("GTitle2");

	m_help = new QToolButton;
	m_help->setObjectName("GToolButton");
	m_help->setCursor(Qt::PointingHandCursor);
	m_help->setIcon(GPicto::Instance()->getPicto(fa::question));
	m_help->setIconSize(QSize(20, 20));

	QToolButton* lClose = new QToolButton;
	lClose->setObjectName("GToolButton2");
	lClose->setCursor(Qt::PointingHandCursor);
	lClose->setIcon(GPicto::Instance()->getPicto(fa::close));
	lClose->setIconSize(QSize(20, 20));

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(m_icon);
	lMainLayout->addWidget(m_title, 1);
	lMainLayout->addWidget(m_help);
	lMainLayout->addWidget(lClose);

	setLayout(lMainLayout);

	connect(lClose, SIGNAL(clicked()), this, SIGNAL(emitWindowClose()));
}
//===============================================
GTitleDialog::~GTitleDialog() {

}
//===============================================
void GTitleDialog::mousePressEvent(QMouseEvent *event) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(event->button() == Qt::LeftButton) {
		QPoint lPressPosition = event->globalPos();
		emit emitWindowPress(lPressPosition);
	}
	QWidget::mousePressEvent(event);
}
//===============================================
void GTitleDialog::mouseMoveEvent(QMouseEvent *event) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(event->buttons() & Qt::LeftButton) {
		QPoint lMovePosition = event->globalPos();
		emit emitWindowMove(lMovePosition);
	}
	QWidget::mouseMoveEvent(event);
}
//===============================================
void GTitleDialog::mouseDoubleClickEvent(QMouseEvent *event) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(event->button() == Qt::LeftButton) {
		emit emitWindowFullScreen();
	}
	QWidget::mouseDoubleClickEvent(event);
}
//===============================================
void GTitleDialog::slotWindowTitleChange(QString title) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	m_title->setText(title);
}
//===============================================
void GTitleDialog::slotWindowIconChange(QIcon icon) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	m_icon->setIcon(icon);
}
//===============================================
