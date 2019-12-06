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
	void (*CreateImg)(char* imgName, char* outName, int depth, int channels);
	void (*CreateParams)(char* imgName, char* outName);
	void (*CreateHalf)(char* imgName, char* outName);
	void (*CreateGray)(char* imgName, char* outName);
	void (*CreateGrayF)(char* imgName, char* outName);
	void (*CreateComplex)(char* imgName, char* outName);
	void (*CreateHeader)(char* imgName, char* outName, CvRect rect);
	void (*Show)(char* imgName, char* windowName);
	void (*Remove)(char* imgName);
	void (*RemoveHeader)(char* imgName);
	void (*Smooth)(char* imgName, char* outName);
	void (*PyrDown)(char* imgName, char* outName);
	void (*Gray)(char* imgName, char* outName);
	void (*Canny)(char* imgName, char* outName, int low, int high, int size);
	void (*Copy)(char* imgName, char* outName);
	void (*Convert)(char* imgName, char* outName);
	void (*ConvertScale)(char* imgName, char* outName, double scale, double shift);
	void (*Clone)(char* imgName, char* outName);
	void (*SetRoi)(char* imgName, CvRect rect);
	void (*SetCoi)(char* imgName, int coi);
	void (*ResetRoi)(char* imgName);
	void (*Not)(char* imgName, char* outName);
	void (*Zero)(char* imgName);
	void (*AddScalar)(char* imgName, char* outName, CvScalar scalar);
	void (*AddWeight)(char* imgName, char* img2Name, char* outName, sGImgWeight weight);
	void (*Line)(char* imgName, sGLine line);
	void (*Rectangle)(char* imgName, sGRectangle rect);
	void (*Circle)(char* imgName, sGCircle circle);
	void (*Split)(char* imgName, char* redName, char* greenName, char* blueName);
	void (*Merge)(char* redName, char* greenName, char* blueName, char* imgName);
	void (*Sum)(char* imgName, char* redName, char* greenName, char* blueName, sGRgbFactor rgbFactor);
	void (*Threshold)(char* imgName, char* outName, sGThreshold thres);
	void (*HoughCircle)(char* imgName, char* storeName, sGHoughCircle houghCircle);
	void (*HoughCircleSet)(char* imgName, char* storeName);
	void (*WarpAffine)(char* imgName, char* outName, char* matName, sGFillFlag fillFlag);
	void (*WarpPerspective)(char* imgName, char* outName, char* matName, sGFillFlag fillFlag);
	void (*LogPolar)(char* imgName, char* outName, sGLogPolar polar);
	void (*DFT)(char* imgName, char* outName, sGDFT dft);
	void (*DFTMagnitude)(char* imgName, char* srcName, char* outName);
	void (*DFTCenter)(char* imgName);
	void (*Magnitude)(char* imgName, char* srcName, char* outName);
	void (*MinMax)(char* imgName, sGMinMax* minMax);
	void (*Pow)(char* imgName, char* outName, double power);
	void (*Add)(char* imgName, char* srcName, char* outName);
	void (*Log)(char* imgName, char* outName);
	void (*Saturate)(char* imgName, sGSaturate* saturate);
	void (*Convolution)(char* imgA, char* imgB, char* imgC);
	void (*SetImage)(char* imgName, void* img);
	void (*SetPixelChannel)(char* imgName, int x, int y, int channel, uchar data);
	void (*GetSize)(char* imgName, CvSize* size);
	void (*GetCenter)(char* imgName, CvPoint* center);
	void (*GetCenterF)(char* imgName, CvPoint2D32f* center);
	void (*GetPointF)(char* imgName, CvPoint2D32f* point, CvPoint2D32f factor);
	void (*GetQuad)(char* imgName, sGQuad* quad);
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
