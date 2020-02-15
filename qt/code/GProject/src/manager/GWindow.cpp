//===============================================
#include "GWindow.h"
#include "GWindowDefault.h"
#include "GImage.h"
#include "GManager.h"
#include "GDebug.h"
//===============================================
GWindow::GWindow(QWidget* parent) :
QFrame(parent) {
	setObjectName("GWindow");
	m_sizeGrip = 0;
}
//===============================================
GWindow::~GWindow() {

}
//===============================================
void GWindow::resizeEvent(QResizeEvent *event) {
	int lSizeGrip = 10;
	m_sizeGrip->setGeometry(width() - lSizeGrip, height() - lSizeGrip, lSizeGrip, lSizeGrip);
}
//===============================================
void GWindow::closeEvent(QCloseEvent *event) {
	GManager::Instance()->save();
}
//===============================================
GWindow* GWindow::Create(QString key) {
	if(key == "DEFAULT") return new GWindowDefault;
	return new GWindowDefault;
}
void GWindow::paintEvent(QPaintEvent *event) {
    QPainter paint(this);
    int widWidth = width();
    int widHeight = height();
    m_pixmapBg = m_pixmapBg.scaled(widWidth, widHeight, Qt::KeepAspectRatioByExpanding);
    QPoint centerOfWidget = rect().center();
    QRect rectOfPixmap = m_pixmapBg.rect();
    rectOfPixmap.moveCenter(centerOfWidget);
    paint.drawPixmap(rectOfPixmap.topLeft(), m_pixmapBg);
}
//===============================================
void GWindow::slotWindowPress(QPoint position) {
	m_pressPosition = position - frameGeometry().topLeft();
}
//===============================================
void GWindow::slotWindowMove(QPoint position) {
	QPoint lMovePosition = position - m_pressPosition;
	move(lMovePosition);
}
//===============================================
void GWindow::slotWindowMinimize() {
	showMinimized();
}
//===============================================
void GWindow::slotWindowMaximize() {
	int lWindowState = windowState();
	if(lWindowState == Qt::WindowMaximized) {
		showNormal();
	}
	else if(lWindowState == Qt::WindowFullScreen) {
		showNormal();
	}
	else {
		showMaximized();
	}
	emit emitWindowMaximize(lWindowState, windowState());
}
//===============================================
void GWindow::slotWindowFullScreen() {
	int lWindowState = windowState();
	if(lWindowState == Qt::WindowFullScreen) {
		showNormal();
	}
	else {
		showFullScreen();
	}
	emit emitWindowFullScreen(lWindowState, windowState());
}
//===============================================
void GWindow::slotModuleMax() {
	GManager::Instance()->infoModuleMax(this);
}
//===============================================
void GWindow::slotModuleMenuAction(QString action, int index) {
	if(action == "IMAGE_OPEN") GImage::Instance()->openImage(this, index, action);
}
//===============================================
void GWindow::slotSettingMenuSelect(QString action) {
	GDebug::Instance()->test();
	if(action == "MANAGER_PRINT") GManager::Instance()->print();
}
//===============================================
