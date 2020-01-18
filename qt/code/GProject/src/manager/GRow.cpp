//===============================================
#include "GRow.h"
#include "GRowDefault.h"
#include "GRowBrowser.h"
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
	if(key == "BROWSER") return new GRowBrowser;
	return new GRowDefault;
}
//===============================================
void GRow::setLabelText(QString) {}
QString GRow::getFieldText() {return "";}
void GRow::slotWindowBrowser() {}
//===============================================
