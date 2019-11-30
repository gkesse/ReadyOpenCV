//===============================================
#include "GStorage.h"
//===============================================
GDECLARE_MAP(GStorage, GCHAR_PTR, GVOID_PTR)
GDEFINE_MAP(GStorage, GCHAR_PTR, GVOID_PTR)
//===============================================
static GStorageO* m_GStorageO = 0;
//===============================================
static void GStorage_CreateStore(char* storeName, int size);
static void GStorage_SetSeq(char* seqName, void* seq);
static CvMemStorage* GStorage_GetStore(char* storeName);
static int GStorage_GetSeqTotal(char* seqName);
static void GStorage_ShowSeqCircle(char* seqName);
static void GStorage_GetSeqCircle(char* seqName, int index, sGCircle* circle);
static void GStorage_Clear(char* storeName);
static void GStorage_Remove(char* storeName);
//===============================================
#if defined(G_USE_OPENCV_ON)
static int GStorage_MapEqual(char* key1, char* key2);
#endif
//===============================================
GStorageO* GStorage_New() {
	GStorageO* lObj = (GStorageO*)malloc(sizeof(GStorageO));

	lObj->m_storeMap = GMap_New_GStorage_GCHAR_PTR_GVOID_PTR();
	lObj->m_seqMap = GMap_New_GStorage_GCHAR_PTR_GVOID_PTR();

	lObj->Delete = GStorage_Delete;
	lObj->CreateStore = GStorage_CreateStore;
	lObj->SetSeq = GStorage_SetSeq;
	lObj->GetStore = GStorage_GetStore;
	lObj->GetSeqTotal = GStorage_GetSeqTotal;
	lObj->ShowSeqCircle = GStorage_ShowSeqCircle;
	lObj->GetSeqCircle = GStorage_GetSeqCircle;
	lObj->Clear = GStorage_Clear;
	lObj->Remove = GStorage_Remove;
	return lObj;
}
//===============================================
void GStorage_Delete() {
	GStorageO* lObj = GStorage();
	if(lObj != 0) {
		free(lObj);
	}
	m_GStorageO = 0;
}
//===============================================
GStorageO* GStorage() {
	if(m_GStorageO == 0) {
		m_GStorageO = GStorage_New();
	}
	return m_GStorageO;
}
//===============================================
static void GStorage_CreateStore(char* storeName, int size) {
#ifdef G_USE_OPENCV_ON
	GMapO(GStorage, GCHAR_PTR, GVOID_PTR)* lStoreMap = m_GStorageO->m_storeMap;
	CvMemStorage* lStore = cvCreateMemStorage(size);
	if(lStore == 0) {printf("[ GStorage ] Error GImage_Create\n"); exit(0);}
	lStoreMap->SetData(lStoreMap, storeName, lStore, GStorage_MapEqual);
#endif
}
//===============================================
static void GStorage_SetSeq(char* seqName, void* seq) {
#ifdef G_USE_OPENCV_ON
	GMapO(GStorage, GCHAR_PTR, GVOID_PTR)* lSeqMap = m_GStorageO->m_seqMap;
	if(seq == 0) {printf("[ GStorage ] Error GStorage_SetSeq\n"); exit(0);}
	lSeqMap->SetData(lSeqMap, seqName, seq, GStorage_MapEqual);
#endif
}
//===============================================
static CvMemStorage* GStorage_GetStore(char* storeName) {
#ifdef G_USE_OPENCV_ON
	GMapO(GStorage, GCHAR_PTR, GVOID_PTR)* lStoreMap = m_GStorageO->m_storeMap;
	CvMemStorage* lStore = lStoreMap->GetData(lStoreMap, storeName, GStorage_MapEqual);
	return lStore;
#endif
}
//===============================================
static void GStorage_GetSeqCircle(char* seqName, int index, sGCircle* circle) {
#ifdef G_USE_OPENCV_ON
	GMapO(GStorage, GCHAR_PTR, GVOID_PTR)* lSeqMap = m_GStorageO->m_seqMap;
	CvSeq* lSeq = lSeqMap->GetData(lSeqMap, seqName, GStorage_MapEqual);
	float* lPoints = (float*)cvGetSeqElem(lSeq, index);
	circle->center = cvPoint(cvRound(lPoints[0]), cvRound(lPoints[1]));
	circle->radius = cvRound(lPoints[2]);
#endif
}
//===============================================
static int GStorage_GetSeqTotal(char* seqName) {
#ifdef G_USE_OPENCV_ON
	GMapO(GStorage, GCHAR_PTR, GVOID_PTR)* lSeqMap = m_GStorageO->m_seqMap;
	CvSeq* lSeq = lSeqMap->GetData(lSeqMap, seqName, GStorage_MapEqual);
	return lSeq->total;
#endif
}
//===============================================
static void GStorage_ShowSeqCircle(char* seqName) {
#ifdef G_USE_OPENCV_ON
	GMapO(GStorage, GCHAR_PTR, GVOID_PTR)* lSeqMap = m_GStorageO->m_seqMap;
	CvSeq* lSeq = lSeqMap->GetData(lSeqMap, seqName, GStorage_MapEqual);
	int lSeqTotal = lSeq->total;
	printf("[ GStrorage ] : SeqTotal: %d\n", lSeqTotal);
	if(lSeqTotal == 0) return;
	sGCircle lCircle;
	for(int i = 0; i < lSeqTotal; i++) {
		GStorage()->GetSeqCircle(seqName, i, &lCircle);
		printf("[ GStrorage ] : SeqCircle[%d][x ; y ; r]: %d ; %d ; %d\n", i, lCircle.center.x, lCircle.center.y, lCircle.radius);
	}
#endif
}
//===============================================
static void GStorage_Clear(char* storeName) {
#ifdef G_USE_OPENCV_ON
	GMapO(GStorage, GCHAR_PTR, GVOID_PTR)* lStoreMap = m_GStorageO->m_storeMap;
	CvMemStorage* lStore = lStoreMap->GetData(lStoreMap, storeName, GStorage_MapEqual);
	cvClearMemStorage(lStore);
#endif
}
//===============================================
static void GStorage_Remove(char* storeName) {
#ifdef G_USE_OPENCV_ON
	GMapO(GStorage, GCHAR_PTR, GVOID_PTR)* lStoreMap = m_GStorageO->m_storeMap;
	CvMemStorage* lStore = lStoreMap->GetData(lStoreMap, storeName, GStorage_MapEqual);
	cvReleaseMemStorage(&lStore);
#endif
}
//===============================================
#if defined(G_USE_OPENCV_ON)
static int GStorage_MapEqual(char* key1, char* key2) {
	int lStrcmp = strcmp(key1, key2);
	if(lStrcmp == 0) return TRUE;
	return FALSE;
}
#endif
//===============================================
