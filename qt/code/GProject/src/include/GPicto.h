//===============================================
#ifndef _GPicto_
#define _GPicto_
//===============================================
#include "GInclude.h"
//===============================================
class GPicto {
private:
	GPicto();

public:
	~GPicto();
	static GPicto* Instance();
	void setColor(QColor color);
	QIcon getPicto(int picto);
	QIcon getPicto(QString picto);

private:
	static GPicto* m_instance;
	QtAwesome* m_picto;
	QColor m_color;

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
