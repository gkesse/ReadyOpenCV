//===============================================
#include "GModuleImage.h"
#include "GPicto.h"
//===============================================
GModuleImage::GModuleImage(QWidget* parent) :
GModule(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	QLabel* lTitle = new QLabel("Image");
	lTitle->setObjectName("title");
	lTitle->setAlignment(Qt::AlignCenter);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(lTitle);

	setLayout(lMainLayout);

	setCursor(Qt::PointingHandCursor);
	setToolTip(tr("Module Image"));
}
//===============================================
GModuleImage::~GModuleImage() {

}
//===============================================
