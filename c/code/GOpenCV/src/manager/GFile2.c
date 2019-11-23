//===============================================
#include "GFile2.h"
#include "GConsole.h"
//===============================================
typedef char* GCHAR_PTR;
typedef FILE* GFILE_PTR;
//===============================================
GDECLARE_MAP(GFile2, GCHAR_PTR, GFILE_PTR)
GDEFINE_MAP(GFile2, GCHAR_PTR, GFILE_PTR)
//===============================================
static GFile2O* m_GFile2O = 0;
//===============================================
static void GFile2_Exist(char* filename);
static void GFile2_Open(char* pFileName, char* filename, char* mode);
static void GFile2_fPrintf(char* pFileName, char* format, ...);
static void GFile2_fScanf(char* pFileName, char* format, ...);
static int GFile2_fSize(char* pFileName);
static void GFile2_fRead(char* pFileName, char* data, int size);
static void GFile2_Close(char* pFileName);
//===============================================
#if defined(__WIN32)
static int GFile2_MapEqual(char* key1, char* key2);
#endif
//===============================================
GFile2O* GFile2_New() {
	GFile2O* lObj = (GFile2O*)malloc(sizeof(GFile2O));

	lObj->m_pFileMap = GMap_New_GFile2_GCHAR_PTR_GFILE_PTR();

	lObj->Delete = GFile2_Delete;
	lObj->Exist = GFile2_Exist;
	lObj->Open = GFile2_Open;
	lObj->fPrintf = GFile2_fPrintf;
	lObj->fScanf = GFile2_fScanf;
	lObj->fSize = GFile2_fSize;
	lObj->fRead = GFile2_fRead;
	lObj->Close = GFile2_Close;
	return lObj;
}
//===============================================
void GFile2_Delete() {
	GFile2O* lObj = GFile2();
	if(lObj != 0) {
		free(lObj);
	}
	m_GFile2O = 0;
}
//===============================================
GFile2O* GFile2() {
	if(m_GFile2O == 0) {
		m_GFile2O = GFile2_New();
	}
	return m_GFile2O;
}
//===============================================
static void GFile2_Exist(char* filename) {
	FILE* lFile = fopen(filename, "r");
	if(lFile == 0) {printf("[ GFile2 ] Error GFile2_Exist: %s\n", filename); exit(0);}
	fclose(lFile);
}
//===============================================
static void GFile2_Open(char* pFileName, char* filename, char* mode) {
	GMapO(GFile2, GCHAR_PTR, GFILE_PTR)* lpFileMap = m_GFile2O->m_pFileMap;
	FILE* lpFile = fopen(filename, mode);
	if(lpFile == 0) {printf("[ GFile2 ] Error GFile2_Open: %s\n", filename); exit(0);}
	lpFileMap->SetData(lpFileMap, pFileName, lpFile, GFile2_MapEqual);
}
//===============================================
static void GFile2_fPrintf(char* pFileName, char* format, ...) {
	GMapO(GFile2, GCHAR_PTR, GFILE_PTR)* lpFileMap = m_GFile2O->m_pFileMap;
	FILE* lpFile = lpFileMap->GetData(lpFileMap, pFileName, GFile2_MapEqual);
	va_list args;
	va_start(args, format);
	int lRes = vfprintf(lpFile, format, args);
	if(lRes < 0) {printf("[ GFile2 ] Error GFile2_fPrintf\n"); exit(0);}
	va_end(args);
}
//===============================================
static void GFile2_fScanf(char* pFileName, char* format, ...) {
	GMapO(GFile2, GCHAR_PTR, GFILE_PTR)* lpFileMap = m_GFile2O->m_pFileMap;
	FILE* lpFile = lpFileMap->GetData(lpFileMap, pFileName, GFile2_MapEqual);
	va_list args;
	va_start(args, format);
	int lRes = vfscanf(lpFile, format, args);
	if(lRes < 0) {printf("[ GFile2 ] Error GFile2_fScanf\n"); exit(0);}
	va_end(args);
}
//===============================================
static int GFile2_fSize(char* pFileName) {
	GMapO(GFile2, GCHAR_PTR, GFILE_PTR)* lpFileMap = m_GFile2O->m_pFileMap;
	FILE* lpFile = lpFileMap->GetData(lpFileMap, pFileName, GFile2_MapEqual);
	fseek(lpFile, 0, SEEK_END);
	int lSize = (int)ftell(lpFile);
	rewind(lpFile);
	return lSize;
}
//===============================================
static void GFile2_fRead(char* pFileName, char* data, int size) {
	GMapO(GFile2, GCHAR_PTR, GFILE_PTR)* lpFileMap = m_GFile2O->m_pFileMap;
	FILE* lpFile = lpFileMap->GetData(lpFileMap, pFileName, GFile2_MapEqual);
	int lBytes = fread(data, sizeof(char), size, lpFile);
	if(lBytes < 0) {printf("[ GFile2 ] Error GFile2_fRead\n"); exit(0);}
	data[lBytes] = 0;
}
//===============================================
static void GFile2_Close(char* pFileName) {
	GMapO(GFile2, GCHAR_PTR, GFILE_PTR)* lpFileMap = m_GFile2O->m_pFileMap;
	FILE* lpFile = lpFileMap->GetData(lpFileMap, pFileName, GFile2_MapEqual);
	fclose(lpFile);
}
//===============================================
#if defined(__WIN32)
static int GFile2_MapEqual(char* key1, char* key2) {
	int lStrcmp = strcmp(key1, key2);
	if(lStrcmp == 0) return TRUE;
	return FALSE;
}
#endif
//===============================================
