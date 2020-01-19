//===============================================
#include "GWorkspaceItemImage.h"
#include "GPicto.h"
//===============================================
GWorkspaceItemImage::GWorkspaceItemImage(QWidget* parent) :
GWorkspaceItem(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	m_workspace = new QLabel(tr("Image"));
	m_workspace->setAlignment(Qt::AlignCenter);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(m_workspace);

	setLayout(lMainLayout);
}
//===============================================
GWorkspaceItemImage::~GWorkspaceItemImage() {

}
//===============================================
