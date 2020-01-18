//===============================================
#include "GWorkspaceItemVideo.h"
#include "GPicto.h"
//===============================================
GWorkspaceItemVideo::GWorkspaceItemVideo(QWidget* parent) :
GWorkspaceItem(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	QLabel* lWorkspace = new QLabel(tr("Video"));
	lWorkspace->setAlignment(Qt::AlignCenter);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(lWorkspace);

	setLayout(lMainLayout);
}
//===============================================
GWorkspaceItemVideo::~GWorkspaceItemVideo() {

}
//===============================================
