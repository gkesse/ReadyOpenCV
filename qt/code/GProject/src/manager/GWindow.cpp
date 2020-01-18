//===============================================
#include "GWindow.h"
#include "GWindowDefault.h"
//===============================================
GWindow::GWindow(QWidget* parent) :
QFrame(parent) {
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
void GWindow::slotWindowPress(QPoint) {}
void GWindow::slotWindowMove(QPoint) {}
void GWindow::slotWindowMinimize() {}
void GWindow::slotWindowMaximize() {}
void GWindow::slotWindowFullScreen() {}
void GWindow::slotModuleImageAction(QString) {}
//===============================================
