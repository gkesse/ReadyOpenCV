//===============================================
#include "GModuleVideo.h"
#include "GPicto.h"
//===============================================
GModuleVideo::GModuleVideo(QWidget* parent) :
GModule(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	QLabel* lTitle = new QLabel("Video");
	lTitle->setObjectName("title");
	lTitle->setAlignment(Qt::AlignCenter);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->addWidget(lTitle);

	setLayout(lMainLayout);

	setCursor(Qt::PointingHandCursor);
	setToolTip(tr("Module Video"));
}
//===============================================
GModuleVideo::~GModuleVideo() {

}
//===============================================
