//===============================================
#include "GTitle.h"
#include "GTitleDefault.h"
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
	return new GTitleDefault;
}
//===============================================
