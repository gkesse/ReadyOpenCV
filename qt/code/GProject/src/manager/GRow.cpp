//===============================================
#include "GRow.h"
#include "GRowDefault.h"
//===============================================
GRow::GRow(QWidget* parent) :
QFrame(parent) {
	setObjectName("GRow");
}
//===============================================
GRow::~GRow() {

}
//===============================================
GRow* GRow::Create(QString key) {
	if(key == "DEFAULT") return new GRowDefault;
	return new GRowDefault;
}
//===============================================
void GRow::setLabelText(QString text) {}
QString GRow::getFieldText() {return "";}
//===============================================
