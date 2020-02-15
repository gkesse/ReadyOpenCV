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
	void loadImage(QString filename, int index, QString action);
	QImage* convertImage(int index, QString action);
	void deleteQImage();

signals:
	void emitImageOpen(int index, QString action);

private:
	static GImage* m_instance;
	QMap<QString, IplImage*> m_imgMap;
	QMap<QString, IplImage*> m_tmpMap;
	IplImage* m_QImage;
	IplImage* m_QImageLast;
};
//===============================================
#endif
//===============================================
