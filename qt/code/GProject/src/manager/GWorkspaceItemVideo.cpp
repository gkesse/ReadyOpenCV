//===============================================
#include "GWorkspaceItemVideo.h"
#include "GPicto.h"
#include "GDebug.h"
//===============================================
GWorkspaceItemVideo::GWorkspaceItemVideo(QString key, QWidget* parent) :
GWorkspaceItem(key, parent) {
	__CLASSNAME__ = __FUNCTION__;
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	m_stackedWidget = new QStackedWidget;

	m_moduleName = tr("Video");
	m_workspaceEmpty = new QLabel;
	m_workspaceEmpty->setAlignment(Qt::AlignCenter);

	m_stackedWidget->addWidget(m_workspaceEmpty);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(m_stackedWidget);

	setLayout(lMainLayout);
}
//===============================================
GWorkspaceItemVideo::~GWorkspaceItemVideo() {

}
//===============================================
