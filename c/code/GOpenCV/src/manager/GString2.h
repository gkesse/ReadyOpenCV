//===============================================
#ifndef _GString2_
#define _GString2_
//===============================================
#include "GInclude.h"
//===============================================
typedef struct _GString2O GString2O;
//===============================================
struct _GString2O {
    void (*Delete)();
    int (*Size)(char* str);
    int (*IsEqual)(char* str1, char* str2);
    char* (*Copy)(char* str);
    char* (*Trim)(char* str);
    char** (*Split)(char* str, char* sep, int* count);
    char* (*ToUpper)(char* str);
    char* (*ToLower)(char* str);
    int (*ToInt)(const char* str);
    double (*ToFloat)(const char* str);
    void (*Free)(char* ptr);
    void (*Free2)(char** ptr, int size);
};
//===============================================
GString2O* GString2_New();
void GString2_Delete();
GString2O* GString2();
//===============================================
#endif
//===============================================
