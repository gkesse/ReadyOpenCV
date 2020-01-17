//===============================================
#include "GImage.h"
#include "GImageOpen.h"
//===============================================
GImage* GImage::m_instance = 0;
//===============================================
GImage::GImage() {

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
void GImage::setParent(QWidget* parent) {
	m_parent = parent;
}
//===============================================
	void GImage::open() {
	GImageOpen* lImageOpen = new GImageOpen(m_parent);
	lImageOpen->setWindowModality(Qt::WindowModal);
	lImageOpen->show();
	//delete lImageOpen;
}
//===============================================
