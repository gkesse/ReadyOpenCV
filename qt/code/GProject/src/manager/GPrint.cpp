//===============================================
#include "GPrint.h"
#include "GDebug.h"
//===============================================
GPrint* GPrint::m_instance = 0;
//===============================================
GPrint::GPrint() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GPrint::~GPrint() {

}
//===============================================
GPrint* GPrint::Instance() {
	if(m_instance == 0) {
		m_instance = new GPrint;
	}
	return m_instance;
}
//===============================================
void GPrint::print(QString data) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	currentDate();
	cout << "QString: ";
	cout << data.toStdString() << "\n";
}
//===============================================
void GPrint::print(QPoint data) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	currentDate();
	cout << "QPoint: ";
	cout << "x: " << data.x() << " ; ";
	cout << "y: " << data.y() << "\n";
}
//===============================================
void GPrint::print(QRect data) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	currentDate();
	cout << "QRect: ";
	cout << "x: " << data.x() << " ; ";
	cout << "y: " << data.y() << " ; ";
	cout << "w: " << data.width() << " ; ";
	cout << "h: " << data.height() << "\n";
}
//===============================================
void GPrint::print(QSize data) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	currentDate();
	cout << "QSize: ";
	cout << "w: " << data.width() << " ; ";
	cout << "h: " << data.height() << "\n";
}
//===============================================
void GPrint::currentDate() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QDateTime lCurrentDate = QDateTime::currentDateTime();
	QString lFormat = lCurrentDate.toString("dd/MM/yyyy HH:mm:ss");
	cout << lFormat.toStdString() << " | ";
}
//===============================================
