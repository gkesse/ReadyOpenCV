//===============================================
#ifndef _GImage_
#define _GImage_
//===============================================
#include "GInclude.h"
//===============================================
class GImage : public QWidget {
	Q_OBJECT

private:
	GImage();

public:
	~GImage();
	static GImage* Instance();
	void openImage(QWidget* parent, int index, QString action);
	void convertImage(QWidget* parent, int index, QString action);
	void convertImage(int index, QString action, QString convertType);
	void convertImageGray();
	QImage convertImage(int index, QString action);
	QImage convertImage(QString actionId);
	void loadImage(QString filename, int index, QString action);
	void removeImage(QString actionId);
	void setImageId(QString imageId);

signals:
	void emitImageOpen(int index, QString action);
	void emitImageOpen(QString actionId);

private:
	static GImage* m_instance;
	QMap<QString, IplImage*> m_imgMap;
	QString m_imageId;

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
