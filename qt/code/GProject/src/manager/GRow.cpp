//===============================================
#include "GRow.h"
#include "GRowDefault.h"
#include "GRowBrowser.h"
//===============================================
GRow::GRow(QWidget* parent) :
QFrame(parent) {
	setObjectName("GRow");
	m_label = 0;
	m_field = 0;
	m_browser = 0;
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
void GRow::setLabelText(QString text) {
	m_label->setText(text);
}
//===============================================
QString GRow::getFieldText() {
	return m_field->text();
}
//===============================================
void GRow::slotWindowBrowser() {
	cout << "GRowBrowser::slotWindowBrowser\n";
}
//===============================================
