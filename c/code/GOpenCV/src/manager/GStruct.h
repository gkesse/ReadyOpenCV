//===============================================
#ifndef _GStruct_
#define _GStruct_
//===============================================
typedef struct _sGSaturate sGSaturate;
typedef struct _sGSaturateItem sGSaturateItem;
typedef struct _sGTestFunc sGTestFunc;
typedef struct _sGImgCreate sGImgCreate;
typedef struct _sGImgWeight sGImgWeight;
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
struct _sGImgCreate {
	CvSize size;
	int deth;
	int nChannels;
};
//===============================================
struct _sGImgWeight {
	double alpha;
	double beta;
	double gamma;
};
//===============================================
#endif
//===============================================
