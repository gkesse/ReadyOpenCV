//===============================================
#include "GDialogImageOpen.h"
#include "GTitle.h"
#include "GButtonMap.h"
#include "GRow.h"
//===============================================
GDialogImageOpen::GDialogImageOpen(QWidget* parent) :
GDialog(parent) {
	GTitle* lTitle = GTitle::Create("DIALOG");

	GRow* lPath = GRow::Create("DEFAULT");
	lPath->setLabelText(tr("Chemin:"));
	GButtonMap* lButtonMap = GButtonMap::Create("OK_CANCEL");

	m_frameLayout->addWidget(lTitle);
	m_frameLayout->addWidget(lPath);
	m_buttonMapLayout->addWidget(lButtonMap);

	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

	connect(lTitle, SIGNAL(emitWindowPress(QPoint)), this, SLOT(slotWindowPress(QPoint)));
	connect(lTitle, SIGNAL(emitWindowMove(QPoint)), this, SLOT(slotWindowMove(QPoint)));
	connect(lTitle, SIGNAL(emitWindowClose()), this, SLOT(reject()));
	connect(lButtonMap, SIGNAL(emitWindowAccept()), this, SLOT(accept()));
	connect(lButtonMap, SIGNAL(emitWindowReject()), this, SLOT(reject()));

	connect(this, SIGNAL(windowTitleChanged(QString)), lTitle, SLOT(slotWindowTitleChange(QString)));
	connect(this, SIGNAL(windowIconChanged(QIcon)), lTitle, SLOT(slotWindowIconChange(QIcon)));

	setWindowTitle(tr("Ouvrir une image | ReadyDev"));
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
