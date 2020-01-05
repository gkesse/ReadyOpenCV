//===============================================
#include "GPrint.h"
//===============================================
GPrint* GPrint::m_instance = 0;
//===============================================
GPrint::GPrint() {

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
	cout << "QString: ";
	cout << data.toStdString() << "\n";
}
//===============================================
void GPrint::print(QPoint data) {
	cout << "QPoint: ";
	cout << "x: " << data.x() << " ; ";
	cout << "y: " << data.y() << "\n";
}
//===============================================
void GPrint::print(QRect data) {
	cout << "QRect: ";
	cout << "x: " << data.x() << " ; ";
	cout << "y: " << data.y() << " ; ";
	cout << "w: " << data.width() << " ; ";
	cout << "h: " << data.height() << "\n";
}
//===============================================
