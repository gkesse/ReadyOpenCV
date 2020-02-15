//===============================================
#include "GWorkspaceItemImage.h"
#include "GPicto.h"
//===============================================
GWorkspaceItemImage::GWorkspaceItemImage(QWidget* parent) :
GWorkspaceItem(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	m_scrollArea = new QScrollArea;
	m_scrollArea->setWidgetResizable(true);
	m_scrollArea->setAlignment(Qt::AlignCenter);

	m_workspace = new QLabel(tr("Image"));
	m_workspace->setAlignment(Qt::AlignCenter);

	m_scrollArea->setWidget(m_workspace);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(m_scrollArea);

	setLayout(lMainLayout);
}
//===============================================
GWorkspaceItemImage::~GWorkspaceItemImage() {

}
//===============================================
