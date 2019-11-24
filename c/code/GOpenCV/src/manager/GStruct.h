//===============================================
#ifndef _GStruct_
#define _GStruct_
//===============================================
typedef struct _sGSaturate sGSaturate;
typedef struct _sGSaturateItem sGSaturateItem;
typedef struct _sGTestFunc sGTestFunc;
//===============================================
typedef void (*GTEST_FUNC)();
//===============================================
struct _sGSaturateItem {
	int flag;
	uchar color;
};
//===============================================
struct _sGSaturate {
	sGSaturateItem red;
	sGSaturateItem green;
	sGSaturateItem blue;
};
//===============================================
struct _sGTestFunc {
	int onFlag;
	char* name;
	GTEST_FUNC func;
};
//===============================================
#endif
//===============================================
