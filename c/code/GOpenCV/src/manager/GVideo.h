//===============================================
#ifndef _GVideo_
#define _GVideo_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GVideoO GVideoO;
typedef struct _GMapO_GVideo_GCHAR_PTR_GVOID_PTR GMapO_GVideo_GCHAR_PTR_GVOID_PTR;
//===============================================
struct _GVideoO {
	void (*Delete)();
	void (*LoadVideo)(char* capName, char* capFile);
	void (*GetImageVideo)(char* capName, char* imgName);
	void (*RemoveVideo)(char* capName);
	GMapO(GVideo, GCHAR_PTR, GVOID_PTR)* m_capMap;
};
//===============================================
GVideoO* GVideo_New();
void GVideo_Delete();
GVideoO* GVideo();
//===============================================
#endif
//===============================================
