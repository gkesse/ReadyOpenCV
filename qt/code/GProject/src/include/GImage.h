//===============================================
#ifndef _GImage_
#define _GImage_
//===============================================
#include "GInclude.h"
//===============================================
class GImage : public QWidget {
	Q_OBJECT

private:
	GImage(QWidget* parent = 0);

public:
	~GImage();
	static GImage* Instance();
	void open(QWidget* parent);

private:
	static GImage* m_instance;
};
//===============================================
#endif
//===============================================
