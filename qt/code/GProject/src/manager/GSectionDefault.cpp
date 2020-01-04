//===============================================
#include "GSectionDefault.h"
#include "GPicto.h"
//===============================================
GSectionDefault::GSectionDefault(QWidget* parent) :
GSection(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;

	QLabel* lModule = new QLabel("Module");

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(lModule);

	//setLayout(lMainLayout);
}
//===============================================
GSectionDefault::~GSectionDefault() {

}
//===============================================
