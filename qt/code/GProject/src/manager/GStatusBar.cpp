//===============================================
#include "GStatusBar.h"
#include "GStatusBarDefault.h"
//===============================================
GStatusBar::GStatusBar(QWidget* parent) :
QWidget(parent) {
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
