//===============================================
#include "GStatusBar.h"
#include "GStatusBarDefault.h"
#include "GDebug.h"
//===============================================
GStatusBar::GStatusBar(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
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
