//===============================================
#include "GSectionDefault.h"
#include "GModule.h"
#include "GPicto.h"
//===============================================
GSectionDefault::GSectionDefault(QWidget* parent) :
GSection(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	QScrollArea* lScrollArea = new QScrollArea;
	QVBoxLayout* lScrollLayout = new QVBoxLayout;
	QWidget* lScrollWidget = new QWidget;

	GModule* lModule;

	lModule = GModule::Create("VIDEO");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("IMAGE");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("VIDEO");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("IMAGE");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("VIDEO");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("IMAGE");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("VIDEO");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("IMAGE");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("VIDEO");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("IMAGE");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("VIDEO");
	lScrollLayout->addWidget(lModule);

	lModule = GModule::Create("IMAGE");
	lScrollLayout->addWidget(lModule);

	lScrollLayout->setMargin(0);
	lScrollLayout->setSpacing(0);
	lScrollLayout->setAlignment(Qt::AlignTop);

	lScrollWidget->setLayout(lScrollLayout);

	lScrollArea->setWidget(lScrollWidget);
	lScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	lScrollArea->setWidgetResizable(true);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(lScrollArea);

	setLayout(lMainLayout);
}
//===============================================
GSectionDefault::~GSectionDefault() {

}
//===============================================
