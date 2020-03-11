//===============================================
#include "GStyle.h"
#include "GDebug.h"
//===============================================
GStyle* GStyle::m_instance = 0;
//===============================================
GStyle::GStyle() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GStyle::~GStyle() {

}
//===============================================
GStyle* GStyle::Instance() {
	if(m_instance == 0) {
		m_instance = new GStyle;
	}
	return m_instance;
}
//===============================================
void GStyle::load(QString filename) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QFile lFile(filename);
	lFile.open(QFile::ReadOnly);
	QString lStyleSheet = QLatin1String(lFile.readAll());
	qApp->setStyleSheet(lStyleSheet);
}
//===============================================
