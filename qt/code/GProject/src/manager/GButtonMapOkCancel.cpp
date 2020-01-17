//===============================================
#include "GButtonMapOkCancel.h"
#include "GPicto.h"
#include "GPrint.h"
//===============================================
GButtonMapOkCancel::GButtonMapOkCancel(QWidget* parent) :
GButtonMap(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	QPushButton* lOk = new QPushButton(tr("Ok"));
	lOk->setCursor(Qt::PointingHandCursor);

	QPushButton* lCancel = new QPushButton(tr("Annuler"));
	lCancel->setCursor(Qt::PointingHandCursor);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignRight);
	lMainLayout->addWidget(lOk);
	lMainLayout->addWidget(lCancel);

	setLayout(lMainLayout);

	connect(lOk, SIGNAL(clicked()), this, SIGNAL(emitWindowAccept()));
	connect(lCancel, SIGNAL(clicked()), this, SIGNAL(emitWindowReject()));
}
//===============================================
GButtonMapOkCancel::~GButtonMapOkCancel() {

}
//===============================================
