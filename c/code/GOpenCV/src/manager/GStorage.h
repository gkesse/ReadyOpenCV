//===============================================
#ifndef _GStorage_
#define _GStorage_
//===============================================
#include "GInclude.h"
#include "GMap.h"
//===============================================
typedef struct _GStorageO GStorageO;
typedef struct _GMapO_GStorage_GCHAR_PTR_GVOID_PTR GMapO_GStorage_GCHAR_PTR_GVOID_PTR;
//===============================================
struct _GStorageO {
	void (*Delete)();
	void (*CreateStore)(char* storeName, int size);
	void (*SetSeq)(char* seqName, void* seq);
	CvMemStorage* (*GetStore)(char* storeName);
	int (*GetSeqTotal)(char* seqName);
	void (*ShowSeqTotal)(char* seqName);
	void (*GetSeqCircle)(char* seqName, int index, sGCircle* circle);
	void (*Clear)(char* storeName);
	void (*Remove)(char* storeName);
	GMapO(GStorage, GCHAR_PTR, GVOID_PTR)* m_storeMap;
	GMapO(GStorage, GCHAR_PTR, GVOID_PTR)* m_seqMap;
};
//===============================================
GStorageO* GStorage_New();
void GStorage_Delete();
GStorageO* GStorage();
//===============================================
#endif
//===============================================
