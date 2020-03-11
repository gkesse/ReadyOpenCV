//===============================================
#include "GRowBrowser.h"
#include "GPicto.h"
#include "GPrint.h"
#include "GDebug.h"
//===============================================
GRowBrowser::GRowBrowser(QWidget* parent) :
GRow(parent) {
	__CLASSNAME__ = __FUNCTION__;
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	m_label = new QLabel;
	m_label->setObjectName("GLabel2");

	m_lineEdit = new QLineEdit;
	m_lineEdit->setObjectName("GLineEdit");

	m_browser = new QToolButton;
	m_browser->setCursor(Qt::PointingHandCursor);
	m_browser->setIcon(GPicto::Instance()->getPicto(fa::folderopen));
	m_browser->setIconSize(QSize(23, 23));

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignLeft);
	lMainLayout->addWidget(m_label);
	lMainLayout->addWidget(m_lineEdit, 1);
	lMainLayout->addWidget(m_browser);

	setLayout(lMainLayout);

	connect(m_browser, SIGNAL(clicked()), this, SLOT(slotWindowBrowser()));
	connect(m_browser, SIGNAL(clicked()), this, SIGNAL(emitWindowBrowser()));
}
//===============================================
GRowBrowser::~GRowBrowser() {

}
//===============================================
