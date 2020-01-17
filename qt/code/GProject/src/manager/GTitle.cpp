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
void GTitle::slotWindowTitleChange(QString title) {}
void GTitle::slotWindowIconChange(QIcon icon) {}
void GTitle::slotWindowMaximize(int oldState, int newState) {}
void GTitle::slotWindowFullScreen(int oldState, int newState) {}
//===============================================
