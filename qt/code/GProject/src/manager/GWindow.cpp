//===============================================
#include "GWindow.h"
#include "GWindowDefault.h"
#include "GImage.h"
#include "GManager.h"
#include "GSetting.h"
#include "GDebug.h"
//===============================================
GWindow::GWindow(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWindow");
	m_sizeGrip = 0;
}
//===============================================
GWindow::~GWindow() {

}
//===============================================
GWindow* GWindow::Create(QString key) {
	if(key == "DEFAULT") return new GWindowDefault;
	return new GWindowDefault;
}
//===============================================
void GWindow::resizeEvent(QResizeEvent *event) {
	//GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	int lSizeGrip = 10;
	m_sizeGrip->setGeometry(width() - lSizeGrip, height() - lSizeGrip, lSizeGrip, lSizeGrip);
}
//===============================================
void GWindow::closeEvent(QCloseEvent *event) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	GManager::Instance()->save();
}
//===============================================
void GWindow::paintEvent(QPaintEvent *event) {
	//GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
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
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	m_pressPosition = position - frameGeometry().topLeft();
}
//===============================================
void GWindow::slotWindowMove(QPoint position) {
	//GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QPoint lMovePosition = position - m_pressPosition;
	move(lMovePosition);
}
//===============================================
void GWindow::slotWindowMinimize() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	showMinimized();
}
//===============================================
void GWindow::slotWindowMaximize() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
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
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
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
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	GManager::Instance()->infoModuleMax(this);
}
//===============================================
void GWindow::slotModuleMenuAction(QString action, int index) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(action == "IMAGE_OPEN") GImage::Instance()->openImage(this, index, action);
	if(action == "IMAGE_CONVERT") GImage::Instance()->convertImage(this, index, action);
	if(action == "IMAGE_CONVERT_GRAY") GImage::Instance()->convertImageGray();
}
//===============================================
void GWindow::slotSettingMenuSelect(QString action) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(action == "MANAGER_PRINT") GManager::Instance()->print();
	else if(action == "SETTING_LOAD") GSetting::Instance()->load();
}
//===============================================
