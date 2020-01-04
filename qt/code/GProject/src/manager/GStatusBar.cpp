//===============================================
#include "GStatusBar.h"
#include "GStatusBarDefault.h"
//===============================================
GStatusBar::GStatusBar(QWidget* parent) :
QFrame(parent) {
	setObjectName("GStatusBar");
}
//===============================================
GStatusBar::~GStatusBar() {

}
//===============================================
GStatusBar* GStatusBar::Create(QString key) {
	if(key == "DEFAULT") return new GStatusBarDefault;
	return new GStatusBarDefault;
}
//===============================================
