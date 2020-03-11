//===============================================
#include "GButtonMap.h"
#include "GButtonMapOkCancel.h"
//===============================================
GButtonMap::GButtonMap(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GButtonMap");
}
//===============================================
GButtonMap::~GButtonMap() {

}
//===============================================
GButtonMap* GButtonMap::Create(QString key) {
	if(key == "OK_CANCEL") return new GButtonMapOkCancel;
	return new GButtonMapOkCancel;
}
//===============================================
