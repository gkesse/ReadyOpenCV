//===============================================
#include "GWindow.h"
#include "GWindowDefault.h"
#include "GManager.h"
//===============================================
GWindow::GWindow(QWidget* parent) :
QFrame(parent) {
	setObjectName("GWindow");
	m_sizeGrip = 0;
	m_shape = 0;

}
//===============================================
GWindow::~GWindow() {
	delete m_shape;
}
//===============================================
void GWindow::paintEvent(QPaintEvent *event) {
	if(m_shape != 0) {
		QPainter lPainter(this);
		lPainter.drawPixmap(0, 0, *m_shape);
	}
}
//===============================================
void GWindow::resizeEvent(QResizeEvent *event) {
	int lSizeGrip = 10;
	m_sizeGrip->setGeometry(width() - lSizeGrip, height() - lSizeGrip, lSizeGrip, lSizeGrip);

	delete m_shape;
	m_shape = new QPixmap(size());
	m_shape->fill(Qt::transparent);
	QPainter lPainter(m_shape);

	QPolygon lShape;
	lShape
	<< QPoint(0, 16)
	<< QPoint(16, 0)
	<< QPoint(width(), 0)
	<< QPoint(width(), height())
	<< QPoint(0, height());
	lPainter.setPen(Qt::NoPen);
	lPainter.setBrush(QBrush("#536d5a"));
	lPainter.drawPolygon(lShape);

	QPolygon lEdge;
	int lMargin = 2;
	lEdge
	<< QPoint(lMargin, 16)
	<< QPoint(16, lMargin)
	<< QPoint(width() - lMargin , lMargin)
	<< QPoint(width() - lMargin, height() - lMargin)
	<< QPoint(lMargin, height() - lMargin);
	lPainter.setPen(QPen(Qt::transparent));
	lPainter.setBrush(Qt::NoBrush);
	lPainter.drawPolygon(lEdge);
}
//===============================================
GWindow* GWindow::Create(QString key) {
	if(key == "DEFAULT") return new GWindowDefault;
	return new GWindowDefault;
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
void GWindow::slotModuleMenuAction(QString action, GModule* module) {
	if(action == "IMAGE_OPEN") GManager::Instance()->openImage(this, module);
}
//===============================================
