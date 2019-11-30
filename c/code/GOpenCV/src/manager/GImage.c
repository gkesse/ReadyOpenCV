//===============================================
#include "GImage.h"
#include "GStorage.h"
#include "GMatrix.h"
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
static void GImage_Clone(char* imgName, char* outName);
static void GImage_SetRoi(char* imgName, CvRect rect);
static void GImage_ResetRoi(char* imgName);
static void GImage_Not(char* imgName, char* outName);
static void GImage_Zero(char* imgName);
static void GImage_AddScalar(char* imgName, char* outName, CvScalar scalar);
static void GImage_AddWeight(char* imgName, char* img2Name, char* outName, sGImgWeight weight);
static void GImage_Line(char* imgName, sGLine line);
static void GImage_Rectangle(char* imgName, sGRectangle rect);
static void GImage_Circle(char* imgName, sGCircle circle);
static void GImage_Split(char* imgName, char* redName, char* greenName, char* blueName);
static void GImage_Merge(char* imgName, char* redName, char* greenName, char* blueName);
static void GImage_Sum(char* imgName, char* redName, char* greenName, char* blueName, sGRgbFactor rgbFactor);
static void GImage_Threshold(char* imgName, char* outName, sGThreshold thres);
static void GImage_HoughCircle(char* imgName, char* storeName, sGHoughCircle houghCircle);
static void GImage_HoughCircleSet(char* imgName, char* storeName);
static void GImage_WarpAffine(char* imgName, char* outName, char* matName);
static void GImage_WarpPerspective(char* imgName, char* outName, char* matName);
static void GImage_Saturate(char* imgName, sGSaturate* saturate);
static void GImage_SetImage(char* imgName, void* img);
static void GImage_SetPixelChannel(char* imgName, int x, int y, int channel, uchar data);
static void GImage_GetSize(char* imgName, CvSize* size);
static void GImage_GetCenter(char* imgName, CvPoint* center);
static void GImage_GetCenterF(char* imgName, CvPoint2D32f* center);
static void GImage_GetPointF(char* imgName, CvPoint2D32f* point, CvPoint2D32f factor);
static void GImage_GetQuad(char* imgName, sGQuad* quad);
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
    lObj->Clone = GImage_Clone;
    lObj->SetRoi = GImage_SetRoi;
    lObj->ResetRoi = GImage_ResetRoi;
    lObj->Not = GImage_Not;
    lObj->Zero = GImage_Zero;
    lObj->AddScalar = GImage_AddScalar;
    lObj->AddWeight = GImage_AddWeight;
    lObj->Line = GImage_Line;
    lObj->Rectangle = GImage_Rectangle;
    lObj->Circle = GImage_Circle;
    lObj->Split = GImage_Split;
    lObj->Merge = GImage_Merge;
    lObj->Sum = GImage_Sum;
    lObj->Threshold = GImage_Threshold;
    lObj->HoughCircle = GImage_HoughCircle;
    lObj->HoughCircleSet = GImage_HoughCircleSet;
    lObj->WarpAffine = GImage_WarpAffine;
    lObj->WarpPerspective = GImage_WarpPerspective;
    lObj->Saturate = GImage_Saturate;
    lObj->SetImage = GImage_SetImage;
    lObj->SetPixelChannel = GImage_SetPixelChannel;
    lObj->GetSize = GImage_GetSize;
    lObj->GetCenter = GImage_GetCenter;
    lObj->GetCenterF = GImage_GetCenterF;
    lObj->GetPointF = GImage_GetPointF;
    lObj->GetQuad = GImage_GetQuad;
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
static void GImage_Clone(char* imgName, char* outName) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    IplImage* lOut = cvCloneImage(lImg);
    lImgMap->SetData(lImgMap, outName, lOut, GImage_MapEqual);
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
static void GImage_Zero(char* imgName) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    cvZero(lImg);
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
static void GImage_Line(char* imgName, sGLine line) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    cvLine(lImg, line.pt1, line.pt2, line.color, line.thickness, 8, 0);
#endif
}
//===============================================
static void GImage_Rectangle(char* imgName, sGRectangle rect) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    cvRectangle(lImg, rect.pt1, rect.pt2, rect.color, rect.thickness, 8, 0);
#endif
}
//===============================================
static void GImage_Circle(char* imgName, sGCircle circle) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    cvCircle(lImg, circle.center, circle.radius, circle.color, circle.thickness, 8, 0);
#endif
}
//===============================================
static void GImage_Split(char* imgName, char* redName, char* greenName, char* blueName) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    IplImage* lRed = lImgMap->GetData(lImgMap, redName, GImage_MapEqual);
    IplImage* lGreen = lImgMap->GetData(lImgMap, greenName, GImage_MapEqual);
    IplImage* lBlue = lImgMap->GetData(lImgMap, blueName, GImage_MapEqual);
    cvSplit(lImg, lRed, lGreen, lBlue, 0);
#endif
}
//===============================================
static void GImage_Merge(char* imgName, char* redName, char* greenName, char* blueName) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    IplImage* lRed = lImgMap->GetData(lImgMap, redName, GImage_MapEqual);
    IplImage* lGreen = lImgMap->GetData(lImgMap, greenName, GImage_MapEqual);
    IplImage* lBlue = lImgMap->GetData(lImgMap, blueName, GImage_MapEqual);
    cvMerge(lRed, lGreen, lBlue, 0, lImg);
#endif
}
//===============================================
static void GImage_Sum(char* imgName, char* redName, char* greenName, char* blueName, sGRgbFactor rgbFactor) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    IplImage* lRed = lImgMap->GetData(lImgMap, redName, GImage_MapEqual);
    IplImage* lGreen = lImgMap->GetData(lImgMap, greenName, GImage_MapEqual);
    IplImage* lBlue = lImgMap->GetData(lImgMap, blueName, GImage_MapEqual);
    double lRedFactor = rgbFactor.redFactor;
    double lGreenFactor = rgbFactor.greenFactor;
    double lBlueFactor = rgbFactor.blueFactor;
    double lRedGreenFactor = lRedFactor + lGreenFactor;
    cvAddWeighted(lRed, lRedFactor, lGreen, lGreenFactor, 0.0, lImg);
    cvAddWeighted(lImg, lRedGreenFactor, lBlue, lBlueFactor, 0.0, lImg);
#endif
}
//===============================================
static void GImage_Threshold(char* imgName, char* outName, sGThreshold thres) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
    cvThreshold(lImg, lOut, thres.thres, thres.max, thres.type);
#endif
}
//===============================================
static void GImage_HoughCircle(char* imgName, char* storeName, sGHoughCircle houghCircle) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    CvMemStorage* lStore = GStorage()->GetStore(storeName);
    int lMethod = houghCircle.method;
    double lDp = houghCircle.dp;
    double lMinDist = lImg->width/10.0;
    CvSeq* lSeq = cvHoughCircles(lImg, lStore, lMethod, lDp, lMinDist, 100, 100, 0, 0);
    GStorage()->SetSeq(storeName, lSeq);
#endif
}
//===============================================
static void GImage_HoughCircleSet(char* imgName, char* storeName) {
#if defined(G_USE_OPENCV_ON)
    int lSeqTotal = GStorage()->GetSeqTotal(storeName);
    sGCircle lCircle = (sGCircle) {
        {0, 0}, 0, CV_RGB(255, 0, 0), 2
    };
    sGCircle lCenter = (sGCircle) {
        {0, 0}, 8, CV_RGB(0, 255, 0), -1
    };
    sGLine lRadius = (sGLine) {
        {0, 0}, {0, 0}, CV_RGB(0, 0, 255), 2
    };
    for(int i = 0; i < lSeqTotal; i++) {
        GStorage()->GetSeqCircle(storeName, i, &lCircle);
        lCenter.center = lCircle.center;
        lRadius.pt1 = lCircle.center;
        lRadius.pt2 = lCircle.center;
        lRadius.pt2.x += lCircle.radius;
        GImage()->Circle(imgName, lCircle);
        GImage()->Circle(imgName, lCenter);
        GImage()->Line(imgName, lRadius);
    }
#endif
}
//===============================================
static void GImage_WarpAffine(char* imgName, char* outName, char* matName) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
    CvMat* lMat = GMatrix()->Get(matName);
    int lFlags = CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS;
    CvScalar lFillVal = cvScalarAll(0);
    cvWarpAffine(lImg, lOut, lMat, lFlags, lFillVal);
#endif
}
//===============================================
static void GImage_WarpPerspective(char* imgName, char* outName, char* matName) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    IplImage* lOut = lImgMap->GetData(lImgMap, outName, GImage_MapEqual);
    CvMat* lMat = GMatrix()->Get(matName);
    int lFlags = CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS;
    CvScalar lFillVal = cvScalarAll(0);
    cvWarpPerspective(lImg, lOut, lMat, lFlags, lFillVal);
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
static void GImage_GetCenter(char* imgName, CvPoint* center) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    center->x = lImg->width/2;
    center->y = lImg->height/2;
#endif
}
//===============================================
static void GImage_GetCenterF(char* imgName, CvPoint2D32f* center) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    center->x = lImg->width/2;
    center->y = lImg->height/2;
#endif
}
//===============================================
static void GImage_GetPointF(char* imgName, CvPoint2D32f* point, CvPoint2D32f factor) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    int lWidth = lImg->width - 1;
    int lHeight = lImg->height - 1;
    point->x = lWidth  * factor.x;
    point->y = lHeight * factor.y;
#endif
}
//===============================================
static void GImage_GetQuad(char* imgName, sGQuad* quad) {
#if defined(G_USE_OPENCV_ON)
    GMapO(GImage, GCHAR_PTR, GVOID_PTR)* lImgMap = m_GImageO->m_imgMap;
    IplImage* lImg = lImgMap->GetData(lImgMap, imgName, GImage_MapEqual);
    int lWidth = lImg->width - 1;
    int lHeight = lImg->height - 1;

    quad->srcQuad[0].x = lWidth  * quad->srcFactor[0].x;
    quad->srcQuad[0].y = lHeight * quad->srcFactor[0].y;
    quad->srcQuad[1].x = lWidth  * quad->srcFactor[1].x;
    quad->srcQuad[1].y = lWidth  * quad->srcFactor[1].y;
    quad->srcQuad[2].x = lHeight * quad->srcFactor[2].x;
    quad->srcQuad[2].y = lHeight * quad->srcFactor[2].y;
    quad->srcQuad[3].x = lWidth  * quad->srcFactor[3].x;
    quad->srcQuad[3].y = lHeight * quad->srcFactor[3].y;

    quad->dstQuad[0].x = lWidth  * quad->dstFactor[0].x;
    quad->dstQuad[0].y = lHeight * quad->dstFactor[0].y;
    quad->dstQuad[1].x = lWidth  * quad->dstFactor[1].x;
    quad->dstQuad[1].y = lWidth  * quad->dstFactor[1].y;
    quad->dstQuad[2].x = lHeight * quad->dstFactor[2].x;
    quad->dstQuad[2].y = lHeight * quad->dstFactor[2].y;
    quad->dstQuad[3].x = lWidth  * quad->dstFactor[3].x;
    quad->dstQuad[3].y = lHeight * quad->dstFactor[3].y;
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
