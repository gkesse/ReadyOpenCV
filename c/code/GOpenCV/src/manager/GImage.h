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
	void (*Create)(char* imgName, CvSize size, int depth, int channels);
	void (*CreateParams)(char* imgName, char* outName);
	void (*CreateHalf)(char* imgName, char* outName);
	void (*CreateGray)(char* imgName, char* outName);
	void (*Show)(char* imgName, char* windowName);
	void (*Remove)(char* imgName);
	void (*Smooth)(char* imgName, char* outName);
	void (*PyrDown)(char* imgName, char* outName);
	void (*Gray)(char* imgName, char* outName);
	void (*Canny)(char* imgName, char* outName, int low, int high, int size);
	void (*Copy)(char* imgName, char* outName);
	void (*Saturate)(char* imgName, sGSaturate* saturate);
	void (*SetImage)(char* imgName, void* img);
	void (*SetPixelChannel)(char* imgName, int x, int y, int channel, uchar data);
	void (*GetSize)(char* imgName, CvSize* size);
	void (*HalfSize)(char* imgName, CvSize* size);
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* m_imgMap;
};
//===============================================
GImageO* GImage_New();
void GImage_Delete();
GImageO* GImage();
//===============================================
#endif
//===============================================
