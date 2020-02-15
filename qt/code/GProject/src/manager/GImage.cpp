//===============================================
#include "GImage.h"
#include "GManager.h"
//===============================================
GImage* GImage::m_instance = 0;
//===============================================
GImage::GImage() {
	m_QImage = 0;
	m_QImageLast = 0;
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
void GImage::openImage(QWidget* parent, int index, QString action) {
	QString lCurrentPath = GManager::Instance()->getCurrentPath();
	QString lFilename = QFileDialog::getOpenFileName(
			parent,
			"Ouvrir une image | ReadyDev",
			lCurrentPath,
			"Image files (*.png *.jpg *.jpeg *.bmp)");

	if(lFilename != "") {
		//GManager::Instance()->setImage(lFilename, index);
		GImage::Instance()->loadImage(lFilename, index, action);
		emit emitImageOpen(index, action);
		//GImage::Instance()->print();
	}
}
//===============================================
void GImage::loadImage(QString filename, int index, QString action) {
	QString lActionId = GManager::Instance()->getActionId(index, action);
	IplImage* lImg = cvLoadImage(filename.toStdString().c_str(), CV_LOAD_IMAGE_COLOR);
	if(lImg == 0) {cout << "Erreur chargement image\n"; return;}
	m_imgMap[lActionId] = lImg;
}
//===============================================
QImage* GImage::convertImage(int index, QString action) {
	QString lActionId = GManager::Instance()->getActionId(index, action);
	IplImage* lImg = m_imgMap[lActionId];
	if(lImg == 0) {cout << "Erreur conversion image\n"; return 0;}
	m_QImageLast = m_QImage;
	m_QImage = cvCreateImage(cvGetSize(lImg), lImg->depth, lImg->nChannels);
	int lFormatCv = CV_BGR2RGB;
	QImage::Format lFormatQt = QImage::Format_RGB888;
	if(lImg->nChannels == 1) {
		lFormatCv = CV_BGR2GRAY;
		lFormatQt = QImage::Format_Indexed8;
	}
	cvCvtColor(lImg, m_QImage, lFormatCv);
	QImage* lQImage = new QImage((const uchar*)(m_QImage->imageData), m_QImage->width, m_QImage->height, m_QImage->widthStep, lFormatQt);
	return lQImage;
}
//===============================================
void GImage::deleteQImage() {
	cvReleaseImage(&m_QImageLast);
}
//===============================================
