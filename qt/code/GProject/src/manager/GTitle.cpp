//===============================================
#include "GTitle.h"
#include "GTitleDefault.h"
#include "GTitleDialog.h"
#include "GPicto.h"
//===============================================
GTitle::GTitle(QWidget* parent) :
QFrame(parent) {
	setObjectName("GTitle");
	m_icon = 0;
	m_title = 0;
	m_maximize = 0;
}
//===============================================
GTitle::~GTitle() {

}
//===============================================
GTitle* GTitle::Create(QString key) {
	if(key == "DEFAULT") return new GTitleDefault;
	if(key == "DIALOG") return new GTitleDialog;
	return new GTitleDefault;
}
//===============================================
void GTitle::mousePressEvent(QMouseEvent *event) {
	if(event->button() == Qt::LeftButton) {
		QPoint lPressPosition = event->globalPos();
		emit emitWindowPress(lPressPosition);
	}
	QWidget::mousePressEvent(event);
}
//===============================================
void GTitle::mouseMoveEvent(QMouseEvent *event) {
	if(event->buttons() & Qt::LeftButton) {
		QPoint lMovePosition = event->globalPos();
		emit emitWindowMove(lMovePosition);
	}
	QWidget::mouseMoveEvent(event);
}
//===============================================
void GTitle::mouseDoubleClickEvent(QMouseEvent *event) {
	if(event->button() == Qt::LeftButton) {
		emit emitWindowFullScreen();
	}
	QWidget::mouseDoubleClickEvent(event);
}
//===============================================
void GTitle::slotWindowTitleChange(QString title) {
	m_title->setText(title);
}
//===============================================
void GTitle::slotWindowIconChange(QIcon icon) {
	m_icon->setIcon(icon);
}
//===============================================
void GTitle::slotWindowMaximize(int oldState, int newState) {
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
void GTitle::slotWindowFullScreen(int oldState, int newState) {
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
