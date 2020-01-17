//===============================================
#include "GRowDefault.h"
#include "GPicto.h"
#include "GPrint.h"
//===============================================
GRowDefault::GRowDefault(QWidget* parent) :
GRow(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	m_label = new QLabel;
	m_label->setObjectName("GLabel2");

	m_field = new QLineEdit;
	m_field->setObjectName("GLineEdit");

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignLeft);
	lMainLayout->addWidget(m_label);
	lMainLayout->addWidget(m_field, 1);

	setLayout(lMainLayout);
}
//===============================================
GRowDefault::~GRowDefault() {

}
//===============================================
void GRowDefault::setLabelText(QString text) {
	m_label->setText(text);
}
//===============================================
QString GRowDefault::getFieldText() {
	return m_field->text();
}
//===============================================
