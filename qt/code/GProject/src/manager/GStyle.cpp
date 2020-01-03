//===============================================
#include "GStyle.h"
//===============================================
GStyle* GStyle::m_instance = 0;
//===============================================
GStyle::GStyle() {

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
	QFile lFile(filename);
	lFile.open(QFile::ReadOnly);
	QString lStyleSheet = QLatin1String(lFile.readAll());
	qApp->setStyleSheet(lStyleSheet);
}
//===============================================
