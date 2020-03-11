//===============================================
#include "GImage.h"
#include "GDialog.h"
#include "GManager.h"
#include "GDebug.h"
//===============================================
GImage* GImage::m_instance = 0;
//===============================================
GImage::GImage() {
	__CLASSNAME__ = __FUNCTION__;
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
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
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
void GImage::convertImage(QWidget* parent, int index, QString action) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	GDialog* lDialog = GDialog::Create("IMAGE_CONVERT", parent);
	int lOk = lDialog->exec();
	if(lOk == QDialog::Accepted) {
		QString lConvertType = lDialog->getConvertType();
		if(lConvertType != "") {
			QString lOpenId = GManager::Instance()->getActionId(index, "IMAGE_OPEN");
			if(m_imgMap.contains(lOpenId) == true ) {
				convertImage(index, action, lConvertType);
				emit emitImageOpen(index, action);
			}
		}
	}
	delete lDialog;
}
//===============================================
QImage GImage::convertImage(int index, QString action) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	int lIndex = GManager::Instance()->getImageIndex();
	QString lActionId = GManager::Instance()->getActionId(index, action, lIndex);
	IplImage* lImg = m_imgMap[lActionId];
	QImage::Format lFormatQt = QImage::Format_RGB888;
	if(lImg->nChannels == 1) {
		lFormatQt = QImage::Format_Indexed8;
	}
	QImage lQImage = QImage((const uchar*)lImg->imageData, lImg->width, lImg->height, lFormatQt);
	if(lImg->nChannels == 3) lQImage = lQImage.rgbSwapped();
	return lQImage;
}
//===============================================
QImage GImage::convertImage(QString actionId) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	IplImage* lImg = m_imgMap[actionId];
	QImage::Format lFormatQt = QImage::Format_RGB888;
	if(lImg->nChannels == 1) {
		lFormatQt = QImage::Format_Indexed8;
	}
	QImage lQImage = QImage((const uchar*)lImg->imageData, lImg->width, lImg->height, lFormatQt);
	if(lImg->nChannels == 3) lQImage = lQImage.rgbSwapped();
	return lQImage;
}
//===============================================
void GImage::convertImage(int index, QString action, QString convertType) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lOpenId = GManager::Instance()->getActionId(index, "IMAGE_OPEN");
	QString lConvertId= GManager::Instance()->getActionId(index, action);
	IplImage* lImg = m_imgMap[lOpenId];
	int lChannels = 3;
	if(convertType.contains("2GRAY")) lChannels = 1;
	IplImage* lOut = cvCreateImage(cvGetSize(lImg), lImg->depth, lChannels);
	int lFormatCv = GEnum::Instance()->getConvertId(convertType);
	cvCvtColor(lImg, lOut, lFormatCv);
	m_imgMap[lConvertId] = lOut;
}
//===============================================
void GImage::convertImageGray() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	IplImage* lImg = m_imgMap[m_imageId];
	IplImage* lTmp = cvCreateImage(cvGetSize(lImg), lImg->depth, 1);
	cvCvtColor(lImg, lTmp, CV_BGR2GRAY);
	cvReleaseImage(&lImg);
	m_imgMap[m_imageId] = lTmp;
	emit emitImageOpen(m_imageId);
}
//===============================================
void GImage::loadImage(QString filename, int index, QString action) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	int lIndex = GManager::Instance()->incrementImageIndex();
	QString lActionId = GManager::Instance()->getActionId(index, action, lIndex);
	IplImage* lImg = cvLoadImage(filename.toStdString().c_str(), CV_LOAD_IMAGE_COLOR);
	m_imgMap[lActionId] = lImg;
}
//===============================================
void GImage::removeImage(QString actionId) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	IplImage* lImg = m_imgMap[actionId];
	cvReleaseImage(&lImg);
}
//===============================================
void GImage::setImageId(QString imageId) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	m_imageId = imageId;
}
//===============================================
