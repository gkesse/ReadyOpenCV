//===============================================
#include "GWindow.h"
#include "GWindowDefault.h"
//===============================================
GWindow::GWindow(QWidget* parent) :
QWidget(parent) {
	setObjectName("GWindow");
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
void GWindow::slotWindowPress(QPoint position) {}
void GWindow::slotWindowMove(QPoint position) {}
void GWindow::slotWindowMinimize() {}
void GWindow::slotWindowMaximize() {}
void GWindow::slotWindowFullScreen() {}
void GWindow::slotWindowAdjustSize() {}
//===============================================
