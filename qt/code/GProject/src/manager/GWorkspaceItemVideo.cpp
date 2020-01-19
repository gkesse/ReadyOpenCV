//===============================================
#include "GWorkspaceItemVideo.h"
#include "GPicto.h"
//===============================================
GWorkspaceItemVideo::GWorkspaceItemVideo(QWidget* parent) :
GWorkspaceItem(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	m_workspace = new QLabel(tr("Video"));
	m_workspace->setAlignment(Qt::AlignCenter);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(m_workspace);

	setLayout(lMainLayout);
}
//===============================================
GWorkspaceItemVideo::~GWorkspaceItemVideo() {

}
//===============================================
