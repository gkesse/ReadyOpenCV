//===============================================
#include "GRowDefault.h"
#include "GPicto.h"
#include "GPrint.h"
#include "GDebug.h"
//===============================================
GRowDefault::GRowDefault(QWidget* parent) :
GRow(parent) {
	__CLASSNAME__ = __FUNCTION__;
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	m_label = new QLabel;
	m_label->setObjectName("GLabel2");

	m_lineEdit = new QLineEdit;
	m_lineEdit->setObjectName("GLineEdit");

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignLeft);
	lMainLayout->addWidget(m_label);
	lMainLayout->addWidget(m_lineEdit, 1);

	setLayout(lMainLayout);
}
//===============================================
GRowDefault::~GRowDefault() {

}
//===============================================
