//===============================================
#include "GRowBrowser.h"
#include "GPicto.h"
#include "GPrint.h"
//===============================================
GRowBrowser::GRowBrowser(QWidget* parent) :
GRow(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	m_label = new QLabel;
	m_label->setObjectName("GLabel2");

	m_field = new QLineEdit;
	m_field->setObjectName("GLineEdit");

	m_browser = new QToolButton;
	m_browser->setObjectName("GToolButton3");
	m_browser->setCursor(Qt::PointingHandCursor);
	m_browser->setIcon(GPicto::Instance()->getPicto(fa::folderopen));
	m_browser->setIconSize(QSize(23, 23));

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignLeft);
	lMainLayout->addWidget(m_label);
	lMainLayout->addWidget(m_field, 1);
	lMainLayout->addWidget(m_browser);

	setLayout(lMainLayout);

	connect(m_browser, SIGNAL(clicked()), this, SLOT(slotWindowBrowser()));
	connect(m_browser, SIGNAL(clicked()), this, SIGNAL(emitWindowBrowser()));
}
//===============================================
GRowBrowser::~GRowBrowser() {

}
//===============================================
void GRowBrowser::setLabelText(QString text) {
	m_label->setText(text);
}
//===============================================
QString GRowBrowser::getFieldText() {
	return m_field->text();
}
//===============================================
void GRowBrowser::slotWindowBrowser() {
	GPrint::Instance()->print("GRowBrowser::slotWindowBrowser");
}
//===============================================
