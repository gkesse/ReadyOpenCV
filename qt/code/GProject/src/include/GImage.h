//===============================================
#ifndef _GImage_
#define _GImage_
//===============================================
#include "GInclude.h"
//===============================================
class GImage {
private:
	GImage();

public:
	~GImage();
	static GImage* Instance();
	void setParent(QWidget* parent);
	void open();

private:
	static GImage* m_instance;
	QWidget* m_parent;
};
//===============================================
#endif
//===============================================
