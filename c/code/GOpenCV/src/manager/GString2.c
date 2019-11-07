//===============================================
#include "GString2.h"
//===============================================
static GString2O* m_GString2O = 0;
//===============================================
static int GString2_Size(char* str);
static int GString2_IsEqual(char* str1, char* str2);
static char* GString2_Copy(char* str);
static char* GString2_Trim(char* str);
static char** GString2_Split(char* str, char* sep, int* count);
static char* GString2_ToUpper(char* str);
static char* GString2_ToLower(char* str);
static void GString2_Free(char* ptr);
static void GString2_Free2(char** ptr, int size);
//===============================================
GString2O* GString2_New() {
    GString2O* lObj = (GString2O*)malloc(sizeof(GString2O));
    lObj->Delete = GString2_Delete;
    lObj->Size = GString2_Size;
    lObj->IsEqual = GString2_IsEqual;
    lObj->Copy = GString2_Copy;
    lObj->Trim = GString2_Trim;
    lObj->Split = GString2_Split;
    lObj->ToUpper = GString2_ToUpper;
    lObj->ToLower = GString2_ToLower;
    lObj->ToInt = atoi;
    lObj->ToFloat = atof;
    lObj->Free = GString2_Free;
    lObj->Free2 = GString2_Free2;
    return lObj; 
}
//===============================================
void GString2_Delete() {
    GString2O* lObj = GString2();
    if(lObj != 0) {
        free(lObj);
    }
    m_GString2O = 0;
}
//===============================================
GString2O* GString2() {
    if(m_GString2O == 0) {
        m_GString2O = GString2_New();
    }
    return m_GString2O;
}
//===============================================
static int GString2_Size(char* str) {
    int i = 0;
    while(str[i] != 0) {i += 1;}
    return i;
}
//===============================================
static int GString2_IsEqual(char* str1, char* str2) {
    int lSize1 = GString2_Size(str1);
    int lSize2 = GString2_Size(str2);
    if(lSize1 != lSize2) {return FALSE;}
    int i = 0;
    while(str1[i] != 0) {
        if(str1[i] != str2[i]) {return FALSE;}
        i += 1;
    }
    return TRUE;
}
//===============================================
static char* GString2_Copy(char* str) {
    int lLength = GString2_Size(str) + 1;
    char* lCopy = (char*)malloc(sizeof(char)*lLength);
    int i = 0;
    while(str[i] != 0) {
        lCopy[i] = str[i];
        i++;
    }
     lCopy[i] = 0;
    return lCopy;
}
//===============================================
static char* GString2_Trim(char* str) {
    if(str[0] == 0) return 0;
    int lStart = 0;
    int lEnd = GString2()->Size(str) - 1;
    while(isspace(str[lStart]) != 0 && lStart < lEnd) lStart++;
    while(isspace(str[lEnd]) != 0 && lEnd > lStart) lEnd--;
    if(lStart == lEnd) {if(isspace(str[lStart]) != 0) {return 0;}}
    lEnd += 1;
    int lLength = lEnd - lStart + 1;
    char* lTrim = (char*)malloc(sizeof(char)*lLength);
    int i = lStart;
    int j = 0;
    while(i < lEnd) {
        lTrim[j] = str[i];
        i++;
        j++;
    }
    lTrim[j] = 0;
    return lTrim;
}
//===============================================
static char** GString2_Split(char* str, char* sep, int* count) {
    int lPos = 0;
    int lCount = 0;
    while(str[lPos] != 0) {
        char lChar = str[lPos];
        char* lSearch = strchr(sep, lChar);
        if(lSearch != 0) lCount++;
        lPos++;
    }
    lCount += 1;
    *count = lCount;
    char** lSplit = (char**)malloc(sizeof(char*)*lCount);
    char* lStr = GString2()->Copy(str);
    char* lToken = strtok(lStr, sep);
    int lTok = 0;
    while(lToken != 0) {
        lSplit[lTok] = GString2()->Copy(lToken);
        lToken = strtok(0, sep);
        lTok++;
    }
    free(lStr);
    return lSplit;
}
//===============================================
static char* GString2_ToUpper(char* str) {
    int lSize = strlen(str) + 1;
    char* lUpper = (char*)malloc(sizeof(char*)*lSize);
    for(int i = 0; i < lSize; i ++) {
        lUpper[i] = toupper(str[i]);
    }
    lUpper[lSize] = 0;
    return lUpper;
}
//===============================================
static char* GString2_ToLower(char* str) {
    int lSize = strlen(str) + 1;
    char* lLower = (char*)malloc(sizeof(char*)*lSize);
    for(int i = 0; i < lSize; i ++) {
        lLower[i] = tolower(str[i]);
    }
    lLower[lSize] = 0;
    return lLower;
}
//===============================================
static void GString2_Free(char* ptr) {
    if(ptr != 0) {
        free(ptr);
        ptr = 0;
    }
}
//===============================================
static void GString2_Free2(char** ptr, int size) {
    if(ptr != 0) {
        for(int i = 0; i < size; i++) {
            if(ptr[i] != 0) {
                free(ptr[i]);
                ptr[i] = 0;
            }
        }
        free(ptr);
        ptr = 0;
    }
}
//===============================================
