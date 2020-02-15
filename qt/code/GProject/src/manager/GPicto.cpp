//===============================================
#include "GPicto.h"
//===============================================
GPicto* GPicto::m_instance = 0;
//===============================================
GPicto::GPicto() {
    m_picto = new QtAwesome(qApp);
    m_picto->initFontAwesome();
    m_color = "white";
}
//===============================================
GPicto::~GPicto() {

}
//===============================================
GPicto* GPicto::Instance() {
	if(m_instance == 0) {
		m_instance = new GPicto;
	}
	return m_instance;
}
//===============================================
void GPicto::setColor(QColor color) {
    m_color = color;
}
//===============================================
QIcon GPicto::getPicto(int picto) {
    m_picto->setDefaultOption("color", m_color);
    m_picto->setDefaultOption("color-active", m_color);
    m_color = "white";
    return m_picto->icon(picto);
}
//===============================================
QIcon GPicto::getPicto(QString picto) {
    m_picto->setDefaultOption("color", m_color);
    m_picto->setDefaultOption("color-active", m_color);
    m_color = "white";
    return m_picto->icon(picto);
}
//===============================================
