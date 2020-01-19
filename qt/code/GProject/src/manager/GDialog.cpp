//===============================================
#include "GDialog.h"
#include "GDialogImageOpen.h"
//===============================================
GDialog::GDialog(QWidget* parent) :
QDialog(parent) {
	QVBoxLayout* lMainLayout = new QVBoxLayout;
	QFrame* lMainFrame = new QFrame;
	QVBoxLayout* lFrameLayout = new QVBoxLayout;

	lMainFrame->setObjectName("GDialog");

	lFrameLayout->setMargin(0);
	lFrameLayout->setSpacing(0);
	lFrameLayout->setAlignment(Qt::AlignTop);

	m_frameLayout = new QVBoxLayout;
	m_frameLayout->setMargin(0);
	m_frameLayout->setSpacing(0);
	m_frameLayout->setAlignment(Qt::AlignTop);

	m_buttonMapLayout = new QHBoxLayout;
	m_buttonMapLayout->setMargin(0);
	m_buttonMapLayout->setSpacing(0);
	m_buttonMapLayout->setAlignment(Qt::AlignRight);

	lFrameLayout->setMargin(0);
	lFrameLayout->setSpacing(0);
	lFrameLayout->setAlignment(Qt::AlignTop);
	lFrameLayout->addLayout(m_frameLayout, 1);
	lFrameLayout->addLayout(m_buttonMapLayout);

	lMainFrame->setLayout(lFrameLayout);

	lMainLayout->setMargin(0);
	lMainLayout->setSpacing(0);
	lMainLayout->setAlignment(Qt::AlignTop);
	lMainLayout->addWidget(lMainFrame);

	setLayout(lMainLayout);
}
//===============================================
GDialog::~GDialog() {

}
//===============================================
GDialog* GDialog::Create(QString key, QWidget* parent) {
	if(key == "IMAGE_OPEN") return new GDialogImageOpen(parent);
	return new GDialogImageOpen;
}
//===============================================
void GDialog::slotWindowPress(QPoint position) {
	m_pressPosition = position - frameGeometry().topLeft();
}
//===============================================
void GDialog::slotWindowMove(QPoint position) {
	QPoint lMovePosition = position - m_pressPosition;
	move(lMovePosition);
}
//===============================================
