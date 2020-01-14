//===============================================
#ifndef _GPrint_
#define _GPrint_
//===============================================
#include "GInclude.h"
//===============================================
class GPrint {
private:
	GPrint();

public:
	~GPrint();
	static GPrint* Instance();
	void print(QString data);
	void print(QPoint data);
	void print(QRect data);
	void print(QSize data);

private:
	void currentDate();

private:
	static GPrint* m_instance;
};
//===============================================
#endif
//===============================================
