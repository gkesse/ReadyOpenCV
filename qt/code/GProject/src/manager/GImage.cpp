//===============================================
#include "GImage.h"
#include "GManager.h"
//===============================================
GImage* GImage::m_instance = 0;
//===============================================
GImage::GImage(QWidget* parent) :
QWidget(parent) {

}
//===============================================
GImage::~GImage() {

}
//===============================================
GImage* GImage::Instance() {
	if(m_instance == 0) {
		m_instance = new GImage;
	}
	return m_instance;
}
//===============================================
void GImage::open(QWidget* parent) {
	QString lFilename = QFileDialog::getOpenFileName(
			parent,
			"Ouvrir une image | ReadyDev",
			QDir::currentPath(),
			"Image files (*.png *.jpg *.jpeg *.bmp)");

	if(lFilename != "") {
		GManager::Instance()->setImage(lFilename.toStdString().c_str());
		GManager::Instance()->print();
	}
}
//===============================================
