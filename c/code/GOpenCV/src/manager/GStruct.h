//===============================================
#ifndef _GStruct_
#define _GStruct_
//===============================================
typedef struct _sGSaturate sGSaturate;
typedef struct _sGSaturateItem sGSaturateItem;
typedef struct _sGTestFunc sGTestFunc;
typedef struct _sGImgCreate sGImgCreate;
typedef struct _sGImgWeight sGImgWeight;
typedef struct _sGRgbFactor sGRgbFactor;
typedef struct _sGThreshold sGThreshold;
typedef struct _sGHoughCircle sGHoughCircle;
typedef struct _sGEvent sGEvent;
typedef struct _sGEventKey sGEventKey;
typedef struct _sGEventMouse sGEventMouse;
typedef struct _sGLine sGLine;
typedef struct _sGRectangle sGRectangle;
typedef struct _sGCircle sGCircle;
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
struct _sGRgbFactor {
	double redFactor;
	double greenFactor;
	double blueFactor;
};
//===============================================
struct _sGThreshold {
	double thres;
	double max;
	int type;
};
//===============================================
struct _sGHoughCircle {
	int method;
	double dp;
	double minDist;
};
//===============================================
struct _sGEventKey {
	int onFlag;
	int key;
	int waitKey;
};
//===============================================
struct _sGEventMouse {
	int onFlag;
	int event;
	int x;
	int y;
};
//===============================================
struct _sGEvent {
	sGEventKey key;
	sGEventMouse mouse;
};
//===============================================
struct _sGLine {
	CvPoint pt1;
	CvPoint pt2;
	CvScalar color;
	int thickness;
};
//===============================================
struct _sGRectangle {
	CvPoint pt1;
	CvPoint pt2;
	CvScalar color;
	int thickness;
	int radius;
};
//===============================================
struct _sGCircle {
	CvPoint center;
	int radius;
	CvScalar color;
	int thickness;
};
//===============================================
#endif
//===============================================
