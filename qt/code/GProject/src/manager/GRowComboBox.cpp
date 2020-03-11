//===============================================
#include "GRowComboBox.h"
#include "GPicto.h"
#include "GPrint.h"
#include "GDebug.h"
//===============================================
GRowComboBox::GRowComboBox(QWidget* parent) :
GRow(parent) {
	__CLASSNAME__ = __FUNCTION__;
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	m_label = new QLabel;
	m_label->setObjectName("GLabel2");
	m_label->setText("Label");

	m_comboBox = new QComboBox;
	m_comboBox->setView(new QListView);
	m_comboBox->setObjectName("GComboBox");
	m_comboBox->addItem("Sélectionner un élément");
	for(int i = 0; i < 10; i++) {
		QString lText = QString("Elément %1").arg(i);
		m_comboBox->addItem(lText);
	}

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignLeft);
	lMainLayout->addWidget(m_label);
	lMainLayout->addWidget(m_comboBox, 1);

	setLayout(lMainLayout);
}
//===============================================
GRowComboBox::~GRowComboBox() {

}
//===============================================
