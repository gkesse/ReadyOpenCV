//===============================================
#include "GEnum.h"
#include "GDebug.h"
//===============================================
GEnum* GEnum::m_instance = 0;
//===============================================
#define G_DEFINE_ENUM_NAME(ID) {1, ID, #ID}
#define G_DEFINE_ENUM_LAST {0, 0, 0}
//===============================================
sGEnum G_ENUM_CONVERT_MAP[] = {
		G_DEFINE_ENUM_NAME(CV_BGR2BGRA),
		G_DEFINE_ENUM_NAME(CV_BGR2BGRA),
		G_DEFINE_ENUM_NAME(CV_BGR2GRAY),
		G_DEFINE_ENUM_NAME(CV_BGR2HSV),
		G_DEFINE_ENUM_NAME(CV_BGR2XYZ),
		G_DEFINE_ENUM_NAME(CV_BGR2RGB),
		G_DEFINE_ENUM_NAME(CV_BGR2RGBA),
		G_DEFINE_ENUM_NAME(CV_BGR2XYZ),
		G_DEFINE_ENUM_NAME(CV_BGR2YCrCb),
		G_DEFINE_ENUM_NAME(CV_BGR2YUV),
		//
		G_DEFINE_ENUM_NAME(CV_BGRA2BGR),
		G_DEFINE_ENUM_NAME(CV_BGRA2GRAY),
		G_DEFINE_ENUM_NAME(CV_BGRA2RGB),
		G_DEFINE_ENUM_NAME(CV_BGRA2RGBA),
		//
		G_DEFINE_ENUM_NAME(CV_RGB2BGR),
		G_DEFINE_ENUM_NAME(CV_RGB2BGRA),
		G_DEFINE_ENUM_NAME(CV_RGB2GRAY),
		G_DEFINE_ENUM_NAME(CV_RGB2HSV),
		G_DEFINE_ENUM_NAME(CV_RGB2RGBA),
		G_DEFINE_ENUM_NAME(CV_RGB2XYZ),
		G_DEFINE_ENUM_NAME(CV_RGB2YCrCb),
		G_DEFINE_ENUM_NAME(CV_RGB2YUV),
		//
		G_DEFINE_ENUM_NAME(CV_RGBA2BGR),
		G_DEFINE_ENUM_NAME(CV_RGBA2BGRA),
		G_DEFINE_ENUM_NAME(CV_RGBA2GRAY),
		G_DEFINE_ENUM_NAME(CV_RGBA2RGB),
		//
		G_DEFINE_ENUM_NAME(CV_GRAY2BGR),
		G_DEFINE_ENUM_NAME(CV_GRAY2BGRA),
		G_DEFINE_ENUM_NAME(CV_GRAY2RGB),
		G_DEFINE_ENUM_NAME(CV_GRAY2RGBA),
		//
		G_DEFINE_ENUM_NAME(CV_HSV2BGR),
		G_DEFINE_ENUM_NAME(CV_HSV2RGB),
		//
		G_DEFINE_ENUM_NAME(CV_XYZ2BGR),
		G_DEFINE_ENUM_NAME(CV_XYZ2RGB),
		//
		G_DEFINE_ENUM_NAME(CV_YCrCb2BGR),
		G_DEFINE_ENUM_NAME(CV_YCrCb2RGB),
		//
		G_DEFINE_ENUM_NAME(CV_YUV2BGR),
		G_DEFINE_ENUM_NAME(CV_YUV2RGB),
		//
		G_DEFINE_ENUM_LAST
};
//===============================================
GEnum::GEnum() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GEnum::~GEnum() {

}
//===============================================
GEnum* GEnum::Instance() {
	if(m_instance == 0) {
		m_instance = new GEnum;
	}
	return m_instance;
}
//===============================================
const char* GEnum::getName(int id, sGEnum* GENUM_MAP) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	int i = 0;
	while(1) {
		sGEnum lEnum = GENUM_MAP[i];
		if(lEnum.onFlag == 0) break;
		if(lEnum.id == id) {return lEnum.name;}
		i++;
	}
	return 0;
}
//===============================================
int GEnum::getId(const char* name, sGEnum* GENUM_MAP) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	int i = 0;
	while(1) {
		sGEnum lEnum = GENUM_MAP[i];
		if(lEnum.onFlag == 0) break;
		if(strcmp(lEnum.name, name) == 0) {return lEnum.id;}
		i++;
	}
	return -1;
}
//===============================================
QStringList GEnum::getNameList(sGEnum* GENUM_MAP) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QStringList lNameMap;
	int i = 0;
	while(1) {
		sGEnum lEnum = GENUM_MAP[i];
		if(lEnum.onFlag == 0) break;
		lNameMap << lEnum.name;
		i++;
	}
	return lNameMap;
}
//===============================================
QStringList GEnum::getConvertNameList() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	return getNameList(G_ENUM_CONVERT_MAP);
}
//===============================================
int GEnum::getConvertId(QString name) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	return getId(name.toStdString().c_str(), G_ENUM_CONVERT_MAP);
}
//===============================================
