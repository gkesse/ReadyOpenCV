//===============================================
#include "GWorkspaceItemImage.h"
#include "GPicto.h"
//===============================================
GWorkspaceItemImage::GWorkspaceItemImage(QWidget* parent) :
GWorkspaceItem(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	QLabel* lWorkspace = new QLabel(tr("Image"));
	lWorkspace->setAlignment(Qt::AlignCenter);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(lWorkspace);

	setLayout(lMainLayout);
}
//===============================================
GWorkspaceItemImage::~GWorkspaceItemImage() {

}
//===============================================
