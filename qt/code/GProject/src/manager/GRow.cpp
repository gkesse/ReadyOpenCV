//===============================================
#include "GRow.h"
#include "GRowDefault.h"
#include "GRowBrowser.h"
#include "GRowComboBox.h"
#include "GDebug.h"
//===============================================
GRow::GRow(QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GRow");
	m_label = 0;
	m_lineEdit = 0;
	m_browser = 0;
	m_comboBox = 0;
}
//===============================================
GRow::~GRow() {

}
//===============================================
GRow* GRow::Create(QString key) {
	if(key == "DEFAULT") return new GRowDefault;
	if(key == "BROWSER") return new GRowBrowser;
	if(key == "COMBOBOX") return new GRowComboBox;
	return new GRowDefault;
}
//===============================================
void GRow::setTextLabel(QString text) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	m_label->setText(text);
}
//===============================================
QString GRow::getTextLineEdit() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	return m_lineEdit->text();
}
//===============================================
void GRow::clearComboBox() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	m_comboBox->clear();
}
//===============================================
void GRow::addDataComboBox(QString text) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	m_comboBox->addItem(text);
}
//===============================================
void GRow::addDataComboBox(QStringList text) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	m_comboBox->addItems(text);
}
//===============================================
QString GRow::getDataComboBox() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	if(m_comboBox->currentIndex() == 0) return "";
	return m_comboBox->currentText();
}
//===============================================
void GRow::slotWindowBrowser() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	cout << "GRowBrowser::slotWindowBrowser\n";
}
//===============================================
