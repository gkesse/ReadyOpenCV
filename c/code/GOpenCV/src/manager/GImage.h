//===============================================
#ifndef _GImage_
#define _GImage_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GImageO GImageO;
typedef struct _GMapO_GImage_GCHAR_PTR_GVOID_PTR GMapO_GImage_GCHAR_PTR_GVOID_PTR;
//===============================================
struct _GImageO {
	void (*Delete)();
	void (*Load)(char* imgName, char* imgFile, int color);
	void (*Show)(char* imgName, char* windowName);
	void (*Remove)(char* imgName);
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* m_imgMap;
};
//===============================================
GImageO* GImage_New();
void GImage_Delete();
GImageO* GImage();
//===============================================
#endif
//===============================================
