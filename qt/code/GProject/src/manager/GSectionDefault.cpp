//===============================================
#include "GSectionDefault.h"
#include "GModule.h"
#include "GPicto.h"
//===============================================
GSectionDefault::GSectionDefault(QWidget* parent) :
GSection(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	GModule* lModule;

	lModule = GModule::Create("VIDEO");
	lMainLayout->addWidget(lModule);

	lModule = GModule::Create("IMAGE");
	lMainLayout->addWidget(lModule);

	lModule = GModule::Create("VIDEO");
	lMainLayout->addWidget(lModule);

	lModule = GModule::Create("IMAGE");
	lMainLayout->addWidget(lModule);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);

	setLayout(lMainLayout);
}
//===============================================
GSectionDefault::~GSectionDefault() {

}
//===============================================
