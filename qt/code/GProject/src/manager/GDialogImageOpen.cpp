//===============================================
#include "GDialogImageOpen.h"
#include "GTitle.h"
//===============================================
GDialogImageOpen::GDialogImageOpen(QWidget* parent) :
GDialog(parent) {
	QHBoxLayout* lMainLayout = new QHBoxLayout;

	GTitle* lTitle = GTitle::Create("DIALOG");

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(lTitle);

	setLayout(lMainLayout);

	//setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

	connect(lTitle, SIGNAL(emitWindowPress(QPoint)), this, SLOT(slotWindowPress(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMove(QPoint)), this, SLOT(slotWindowMove(QPoint)));
	connect(lTitle, SIGNAL(emitWindowClose()), this, SLOT(close()));

	connect(this, SIGNAL(windowTitleChanged(QString)), lTitle, SLOT(slotWindowTitleChange(QString)));
	connect(this, SIGNAL(windowIconChanged(QIcon)), lTitle, SLOT(slotWindowIconChange(QIcon)));

	setWindowTitle(tr("OpenCV | ReadyDev"));
	if(parent != 0) setWindowIcon(parent->windowIcon());
}
//===============================================
GDialogImageOpen::~GDialogImageOpen() {

}
//===============================================
void GDialogImageOpen::slotWindowPress(QPoint position) {
	m_pressPosition = position - frameGeometry().topLeft();
}
//===============================================
void GDialogImageOpen::slotWindowMove(QPoint position) {
	QPoint lMovePosition = position - m_pressPosition;
	move(lMovePosition);
}
//===============================================
