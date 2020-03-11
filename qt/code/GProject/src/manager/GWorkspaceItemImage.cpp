//===============================================
#include "GWorkspaceItemImage.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
GWorkspaceItemImage::GWorkspaceItemImage(QString key, QWidget* parent) :
GWorkspaceItem(key, parent) {
	__CLASSNAME__ = __FUNCTION__;
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	m_stackedWidget = new QStackedWidget;

	m_moduleName = tr("Image");
	m_workspaceEmpty = new QLabel;
	m_workspaceEmpty->setAlignment(Qt::AlignCenter);

	m_tabWidget = new QTabWidget;
	m_tabWidget->tabBar()->setExpanding(false);
	m_tabWidget->setTabsClosable(true);

	m_stackedWidget->addWidget(m_workspaceEmpty);
	m_stackedWidget->addWidget(m_tabWidget);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(m_stackedWidget);

	setLayout(lMainLayout);

	connect(m_tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(slotTabCloseRequest(int)));
	connect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(slotTabCurrentChange(int)));
}
//===============================================
GWorkspaceItemImage::~GWorkspaceItemImage() {

}
//===============================================
