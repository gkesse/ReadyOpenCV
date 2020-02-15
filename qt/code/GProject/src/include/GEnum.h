//===============================================
#ifndef _GEnum_
#define _GEnum_
//===============================================
#include "GInclude.h"
//===============================================
class GEnum {
private:
	GEnum();

public:
	~GEnum();
	static GEnum* Instance();
	const char* getName(int id);
	int getId(const char* name);

private:
	static GEnum* m_instance;
};
//===============================================
typedef enum _eGEnum {
	G_UNKNOWN,
	G_IMAGE_OPEN,
	G_IMAGE_SAVE,
	G_VIDEO_OPEN,
	G_VIDEO_SAVE,
	G_LAST
} eGEnum;
//===============================================
typedef struct _sGEnum {
	int onFlag;
	int id;
	const char* name;
} sGEnum;
//===============================================
#endif
//===============================================
