//===============================================
#include "GMenu.h"
#include "GMenuDefault.h"
//===============================================
GMenu::GMenu(QWidget* parent) :
QFrame(parent) {
	setObjectName("GMenu");
}
//===============================================
GMenu::~GMenu() {

}
//===============================================
GMenu* GMenu::Create(QString key) {
	if(key == "DEFAULT") return new GMenuDefault;
	return new GMenuDefault;
}
//===============================================
