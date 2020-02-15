//===============================================
#include "GEnum.h"
//===============================================
GEnum* GEnum::m_instance = 0;
//===============================================
#define GDEFINE_ENUM_NAME(ID) {1, ID, #ID}
#define GDEFINE_ENUM_LAST {0, 0, 0}
//===============================================
sGEnum GENUM_MAP[] = {
		GDEFINE_ENUM_NAME(G_UNKNOWN),
		GDEFINE_ENUM_NAME(G_IMAGE_OPEN),
		GDEFINE_ENUM_NAME(G_IMAGE_SAVE),
		GDEFINE_ENUM_NAME(G_VIDEO_OPEN),
		GDEFINE_ENUM_NAME(G_VIDEO_SAVE),
		GDEFINE_ENUM_NAME(G_UNKNOWN),
		GDEFINE_ENUM_LAST
};
//===============================================
GEnum::GEnum() {

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
const char* GEnum::getName(int id) {
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
int GEnum::getId(const char* name) {
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
