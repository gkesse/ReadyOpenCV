//===============================================
#include "GImage.h"
//===============================================
GDECLARE_MAP(GImage, GCHAR_PTR, GVOID_PTR)
GDEFINE_MAP(GImage, GCHAR_PTR, GVOID_PTR)
//===============================================
static GImageO* m_GImageO = 0;
//===============================================
static void GImage_Load(char* imgName, char* imgFile, int color);
static void GImage_Create(char* imgName, CvSize size, int depth, int channels);
static void GImage_CreateParams(char* imgName, char* outName);
static void GImage_CreateHalf(char* imgName, char* outName);
static void GImage_CreateGray(char* imgName, char* outName);
static void GImage_CreateHeader(char* imgName, char* outName, CvRect rect);
static void GImage_Show(char* imgName, char* windowName);
static void GImage_Remove(char* imgName);
static void GImage_RemoveHeader(char* imgName);
static void GImage_Smooth(char* imgName, char* outName);
static void GImage_PyrDown(char* imgName, char* outName);
static void GImage_Gray(char* imgName, char* outName);
static void GImage_Canny(char* imgName, char* outName, int low, int high, int size);
static void GImage_Copy(char* imgName, char* outName);
static void GImage_SetRoi(char* imgName, CvRect rect);
static void GImage_ResetRoi(char* imgName);
static void GImage_Not(char* imgName, char* outName);
static void GImage_AddScalar(char* imgName, char* outName, CvScalar scalar);
static void GImage_AddWeight(char* imgName, char* img2Name, char* outName, sGImgWeight weight);
static void GImage_Saturate(char* imgName, sGSaturate* saturate);
static void GImage_SetImage(char* imgName, void* img);
static void GImage_SetPixelChannel(char* imgName, int x, int y, int channel, uchar data);
static void GImage_GetSize(char* imgName, CvSize* size);
static void GImage_HalfSize(char* imgName, CvSize* size);
//===============================================
#if defined(G_USE_OPENCV_ON)
static int GImage_MapEqual(char* key1, char* key2);
#endif
//===============================================
GImageO* GImage_New() {
	GImageO* lObj = (GImageO*)malloc(sizeof(GImageO));

	lObj->m_imgMap = GMap_New_GImage_GCHAR_PTR_GVOID_PTR();

	lObj->Delete = GImage_Delete;
	lObj->Load = GImage_Load;
	lObj->Create = GImage_Create;
	lObj->CreateParams = GImage_CreateParams;
	lObj->CreateHalf = GImage_CreateHalf;
	lObj->CreateGray = GImage_CreateGray;
	lObj->CreateHeader = GImage_CreateHeader;
	lObj->Show = GImage_Show;
	lObj->Remove = GImage_Remove;
	lObj->RemoveHeader = GImage_RemoveHeader;
	lObj->Smooth = GImage_Smooth;
	lObj->PyrDown = GImage_PyrDown;
	lObj->Gray = GImage_Gray;
	lObj->Canny = GImage_Canny;
	lObj->Copy = GImage_Copy;
	lObj->SetRoi = GImage_SetRoi;
	lObj->ResetRoi = GImage_ResetRoi;
	lObj->Not = GImage_Not;
	lObj->AddScalar = GImage_AddScalar;
	lObj->AddWeight = GImage_AddWeight;
	lObj->Saturate = GImage_Saturate;
	lObj->SetImage = GImage_SetImage;
	lObj->SetPixelChannel = GImage_SetPixelChannel;
	lObj->GetSize = GImage_GetSize;
	lObj->HalfSize = GImage_HalfSize;
	return lObj;
}
//===============================================
void GImage_Delete() {
	GImageO* lObj = GImage();
	if(lObj != 0) {
		free(lObj);
	}
	m_GImageO = 0;
}
//===============================================
GImageO* GImage() {
	if(m_GImageO == 0) {
		m_GImageO = GImage_New();
	}
	return m_GImageO;
}
//===============================================
static void GImage_Load(char* imgName, char* imgFile, int color) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = cvLoadImage(imgFile, color);
	if(lImg == 0) {printf("[ GImage ] Error GImage_Load: %s\n", imgFile); exit(0);}
	lImgMap->SetData(lImgMap, imgName, lImg, GImage_MapEqual);
#endif
}
//===============================================
static void GImage_Create(char* imgName, CvSize size, int depth, int channels) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = cvCreateImage(size, depth, channels);
	if(lImg == 0) {printf("[ GImage ] Error GImage_Create\n"); exit(0);}
	lImgMap->SetData(lImgMap, imgName, lImg, GImage_MapEqual);
#endif
}
//===============================================
static void GImage_CreateParams(char* imgName, char* outName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	CvSize lSize = cvGetSize(lImg);
	int lDeth = lImg->depth;
	int lChannels = lImg->nChannels;
	IplImage* lOut = cvCreateImage(lSize, lDeth, lChannels);
	if(lOut == 0) {printf("[ GImage ] Error GImage_CreateParams\n"); exit(0);}
	lImgMap->SetData(lImgMap, outName, lOut, GImage_MapEqual);
#endif
}
//===============================================
static void GImage_CreateHalf(char* imgName, char* outName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	CvSize lSize;
	GImage()->HalfSize(imgName, &lSize);
	int lDeth = lImg->depth;
	int lChannels = lImg->nChannels;
	IplImage* lOut = cvCreateImage(lSize, lDeth, lChannels);
	if(lOut == 0) {printf("[ GImage ] Error GImage_CreateParams\n"); exit(0);}
	lImgMap->SetData(lImgMap, outName, lOut, GImage_MapEqual);
#endif
}
//===============================================
static void GImage_CreateGray(char* imgName, char* outName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	CvSize lSize = cvGetSize(lImg);
	int lDeth = lImg->depth;
	int lChannels = 1;
	IplImage* lOut = cvCreateImage(lSize, lDeth, lChannels);
	if(lOut == 0) {printf("[ GImage ] Error GImage_CreateGray\n"); exit(0);}
	lImgMap->SetData(lImgMap, outName, lOut, GImage_MapEqual);
#endif
}
//===============================================
static void GImage_CreateHeader(char* imgName, char* outName, CvRect rect) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	CvSize lSize = cvSize(rect.width, rect.height);
	int lDeth = lImg->depth;
	int lChannels = lImg->nChannels;
	IplImage* lOut = cvCreateImageHeader(lSize, lDeth, lChannels);
	lOut->origin = lImg->origin;
	lOut->widthStep = lImg->widthStep;

	int lX = rect.x;
	int lY = rect.y;

	int k = 0;
	k += lX*lChannels;
	k += lY*lImg->widthStep;

	lOut->imageData = &lImg->imageData[k];

	if(lOut == 0) {printf("[ GImage ] Error GImage_CreateGray\n"); exit(0);}
	lImgMap->SetData(lImgMap, outName, lOut, GImage_MapEqual);
#endif
}
//===============================================
static void GImage_Show(char* imgName, char* windowName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	cvShowImage(windowName, lImg);
#endif
}
//===============================================
static void GImage_Remove(char* imgName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	cvReleaseImage(&lImg);
#endif
}
//===============================================
static void GImage_RemoveHeader(char* imgName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	cvReleaseImageHeader(&lImg);
#endif
}
//===============================================
static void GImage_Smooth(char* imgName, char* outName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
	cvSmooth(lImg, lOut, CV_GAUSSIAN, 3, 3, 0, 0);
#endif
}
//===============================================
static void GImage_PyrDown(char* imgName, char* outName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
	cvPyrDown(lImg, lOut, CV_GAUSSIAN_5x5);
#endif
}
//===============================================
static void GImage_Gray(char* imgName, char* outName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
	cvCvtColor(lImg, lOut, CV_BGR2GRAY);
#endif
}
//===============================================
static void GImage_Canny(char* imgName, char* outName, int low, int high, int size) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
	cvCanny(lImg, lOut, low, high, size);
#endif
}
//===============================================
static void GImage_Copy(char* imgName, char* outName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
	cvCopy(lImg, lOut, 0);
#endif
}
//===============================================
static void GImage_SetRoi(char* imgName, CvRect rect) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	cvSetImageROI(lImg, rect);
#endif
}
//===============================================
static void GImage_ResetRoi(char* imgName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	cvResetImageROI(lImg);
#endif
}
//===============================================
static void GImage_Not(char* imgName, char* outName) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
	cvNot(lImg, lOut);
#endif
}
//===============================================
static void GImage_AddScalar(char* imgName, char* outName, CvScalar scalar) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
	cvAddS(lImg, scalar, lOut, 0);
#endif
}
//===============================================
static void GImage_AddWeight(char* imgName, char* img2Name, char* outName, sGImgWeight weight) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	IplImage* lImg2 = lImgMap->GetData(lImgMap, img2Name, GImage_MapEqual);
	IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
	double lApha = weight.alpha;
	double lBeta = weight.beta;
	double lGamma = weight.gamma;
	cvAddWeighted(lImg, lApha, lImg2, lBeta, lGamma, lOut);
#endif
}
//===============================================
static void GImage_Saturate(char* imgName, sGSaturate* saturate) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	sGSaturateItem* lRed = &saturate->red;
	sGSaturateItem* lGreen = &saturate->green;
	sGSaturateItem* lBlue = &saturate->blue;
	for(int j = 0; j < lImg->height; j++) {
		for(int i = 0; i < lImg->width; i++) {
			if(lRed->flag == 1) GImage()->SetPixelChannel(imgName, i, j, 2, lRed->color);
			if(lGreen->flag == 1) GImage()->SetPixelChannel(imgName, i, j, 1, lGreen->color);
			if(lBlue->flag == 1) GImage()->SetPixelChannel(imgName, i, j, 0, lBlue->color);
		}
	}
#endif
}
//===============================================
static void GImage_SetPixelChannel(char* imgName, int x, int y, int channel, uchar data) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	uchar* lData = (uchar*)lImg->imageData;
	int lWidth = lImg->width;
	int lChannels = lImg->nChannels;
	int k = 0;
	k += channel;
	k += x*lChannels;
	k += y*lChannels*lWidth;
	lData[k] = data;
#endif
}
//===============================================
static void GImage_SetImage(char* imgName, void* img) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	lImgMap->SetData(lImgMap, imgName, img, GImage_MapEqual);
#endif
}
//===============================================
static void GImage_GetSize(char* imgName, CvSize* size) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	*size = cvGetSize(lImg);
#endif
}
//===============================================
static void GImage_HalfSize(char* imgName, CvSize* size) {
#if defined(G_USE_OPENCV_ON)
	GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
	IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
	CvSize lSize = cvGetSize(lImg);
	*size = cvSize(lSize.width/2, lSize.height/2);
#endif
}
//===============================================
#if defined(G_USE_OPENCV_ON)
static int GImage_MapEqual(char* key1, char* key2) {
	int lStrcmp = strcmp(key1, key2);
	if(lStrcmp == 0) return TRUE;
	return FALSE;
}
#endif
//===============================================
