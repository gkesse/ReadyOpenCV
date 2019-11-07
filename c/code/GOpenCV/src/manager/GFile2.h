//===============================================
#ifndef _GFile2_
#define _GFile2_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GFile2O GFile2O;
typedef struct _GMapO_GFile2_GCHAR_PTR_GFILE_PTR GMapO_GFile2_GCHAR_PTR_GFILE_PTR;
//===============================================
struct _GFile2O {
	void (*Delete)();
	void (*Exist)(char* filename);
	void (*Open)(char* pFileName, char* filename, char* mode);
	void (*fPrintf)(char* pFileName, char* format, ...);
	void (*fScanf)(char* pFileName, char* format, ...);
	int (*fSize)(char* pFileName);
	void (*fRead)(char* pFileName, char* data, int size);
	void (*Close)(char* pFileName);
	GMapO(GFile2, GCHAR_PTR, GFILE_PTR)* m_pFileMap;
};
//===============================================
GFile2O* GFile2_New();
void GFile2_Delete();
GFile2O* GFile2();
//===============================================
#endif
//===============================================
