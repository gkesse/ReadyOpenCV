//===============================================
#include "GDialog.h"
#include "GDialogImageOpen.h"
//===============================================
GDialog::GDialog(QWidget* parent) :
QDialog(parent) {
	setObjectName("GDialog");
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
void GDialog::slotWindowPress(QPoint position) {}
void GDialog::slotWindowMove(QPoint position) {}
//===============================================
