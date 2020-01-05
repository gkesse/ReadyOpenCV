//===============================================
#include "GStatusBarDefault.h"
#include "GPicto.h"
//===============================================
GStatusBarDefault::GStatusBarDefault(QWidget* parent) :
GStatusBar(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	QLabel* lStatusBar = new QLabel("StatusBar");
	lStatusBar->setObjectName("status_bar");

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignLeft);
	lMainLayout->addWidget(lStatusBar);

	setLayout(lMainLayout);
}
//===============================================
GStatusBarDefault::~GStatusBarDefault() {

}
//===============================================
