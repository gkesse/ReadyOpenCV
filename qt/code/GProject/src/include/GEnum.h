//===============================================
#ifndef _GEnum_
#define _GEnum_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _sGEnum {
	int onFlag;
	int id;
	const char* name;
} sGEnum;
//===============================================
class GEnum {
private:
	GEnum();

public:
	~GEnum();
	static GEnum* Instance();
	const char* getName(int id, sGEnum* GENUM_MAP);
	int getId(const char* name, sGEnum* GENUM_MAP);
	QStringList getNameList(sGEnum* GENUM_MAP);
	QStringList getConvertNameList();
	int getConvertId(QString name);

private:
	static GEnum* m_instance;

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
