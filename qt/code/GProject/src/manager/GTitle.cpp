//===============================================
#include "GTitle.h"
#include "GTitleDefault.h"
#include "GTitleDialog.h"
//===============================================
GTitle::GTitle(QWidget* parent) :
QFrame(parent) {
	setObjectName("GTitle");
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
void GTitle::slotWindowTitleChange(QString) {}
void GTitle::slotWindowIconChange(QIcon) {}
void GTitle::slotWindowMaximize(int, int) {}
void GTitle::slotWindowFullScreen(int, int) {}
//===============================================
