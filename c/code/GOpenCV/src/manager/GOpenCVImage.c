//===============================================
#include "GOpenCVImage.h"
#include "GImage.h"
#include "GWindow.h"
#include "GEvent.h"
#include "GStorage.h"
#include "GMatrix.h"
#include "GConfig.h"
#include "GString2.h"
//===============================================
static GOpenCVImageO* m_GOpenCVImageO = 0;
//===============================================
static void GOpenCVImage_Run();
static void GOpenCVImage_RunNumber();
static void GOpenCVImage_RunFunc();
static void GOpenCVImage_RunLast();
static void GOpenCVImage_RunAll();
//===============================================
static void GOpenCVImage_Load();
static void GOpenCVImage_Gray();
static void GOpenCVImage_Smooth();
static void GOpenCVImage_Canny();
static void GOpenCVImage_PyrDown();
static void GOpenCVImage_Saturate();
static void GOpenCVImage_Roi();
static void GOpenCVImage_Header();
static void GOpenCVImage_Blend();
static void GOpenCVImage_Rectangle();
static void GOpenCVImage_Split();
static void GOpenCVImage_Merge();
static void GOpenCVImage_Sum();
static void GOpenCVImage_AddWeight();
static void GOpenCVImage_Threshold();
static void GOpenCVImage_HoughCircle();
static void GOpenCVImage_WarpAffine();
static void GOpenCVImage_WarpPerspective();
static void GOpenCVImage_LogPolar();
static void GOpenCVImage_DFT();
static void GOpenCVImage_Convolution();
//===============================================
#define GDEFINE_TEST_FUNC(GFUNC) {1, #GFUNC, GFUNC}
#define GDEFINE_TEST_FUNC_LAST {0, 0, 0}
//===============================================
typedef void (*GTEST_FUNC)();
//===============================================
static sGTestFunc GTEST_FUNC_MAP[] = {
        GDEFINE_TEST_FUNC(GOpenCVImage_RunNumber),
        GDEFINE_TEST_FUNC(GOpenCVImage_Load),
        GDEFINE_TEST_FUNC(GOpenCVImage_Gray),
        GDEFINE_TEST_FUNC(GOpenCVImage_Smooth),
        GDEFINE_TEST_FUNC(GOpenCVImage_Canny),
        GDEFINE_TEST_FUNC(GOpenCVImage_PyrDown),
        GDEFINE_TEST_FUNC(GOpenCVImage_Saturate),
        GDEFINE_TEST_FUNC(GOpenCVImage_Roi),
        GDEFINE_TEST_FUNC(GOpenCVImage_Header),
        GDEFINE_TEST_FUNC(GOpenCVImage_Blend),
        GDEFINE_TEST_FUNC(GOpenCVImage_Rectangle),
        GDEFINE_TEST_FUNC(GOpenCVImage_Split),
        GDEFINE_TEST_FUNC(GOpenCVImage_Merge),
        GDEFINE_TEST_FUNC(GOpenCVImage_Sum),
        GDEFINE_TEST_FUNC(GOpenCVImage_AddWeight),
        GDEFINE_TEST_FUNC(GOpenCVImage_Threshold),
        GDEFINE_TEST_FUNC(GOpenCVImage_HoughCircle),
        GDEFINE_TEST_FUNC(GOpenCVImage_WarpAffine),
        GDEFINE_TEST_FUNC(GOpenCVImage_WarpPerspective),
        GDEFINE_TEST_FUNC(GOpenCVImage_LogPolar),
        GDEFINE_TEST_FUNC(GOpenCVImage_DFT),
        GDEFINE_TEST_FUNC(GOpenCVImage_Convolution),
        GDEFINE_TEST_FUNC_LAST
};
//===============================================
GOpenCVImageO* GOpenCVImage_New() {
    GOpenCVImageO* lObj = (GOpenCVImageO*)malloc(sizeof(GOpenCVImageO));
    lObj->m_continue = TRUE;
    lObj->Delete = GOpenCVImage_Delete;
    lObj->Run = GOpenCVImage_Run;
    return lObj;
}
//===============================================
void GOpenCVImage_Delete() {
    GOpenCVImageO* lObj = GOpenCVImage();
    if(lObj != 0) {
        free(lObj);
    }
    m_GOpenCVImageO = 0;
}
//===============================================
GOpenCVImageO* GOpenCVImage() {
    if(m_GOpenCVImageO == 0) {
        m_GOpenCVImageO = GOpenCVImage_New();
    }
    return m_GOpenCVImageO;
}
//===============================================
static void GOpenCVImage_Run() {
    char* lOption1 = GConfig()->GetData("OPTION_1");
    if(GString2()->IsEqual(lOption1, "")) GOpenCVImage_RunNumber();
    else if(GString2()->IsEqual(lOption1, "-1")) GOpenCVImage_RunNumber();
    else if(GString2()->IsEqual(lOption1, "-2")) GOpenCVImage_RunLast();
    else if(GString2()->IsEqual(lOption1, "-3")) GOpenCVImage_RunAll();
    else GOpenCVImage_RunFunc();
}
//===============================================
static void GOpenCVImage_RunNumber() {
    int i = 0;
    while(1) {
        sGTestFunc lTestFunc = GTEST_FUNC_MAP[i];
        int lOnFlag = lTestFunc.onFlag;
        if(lOnFlag == 0) break;
        char* lName = lTestFunc.name;
        printf("%-2d : %s\n", i, lName);
        i++;
    }
}
//===============================================
static void GOpenCVImage_RunFunc() {
    char* lOption1 = GConfig()->GetData("OPTION_1");
    int lFuncId = GString2()->ToInt(lOption1);
    int i = 0;
    while(1) {
        sGTestFunc lTestFunc = GTEST_FUNC_MAP[i];
        int lOnFlag = lTestFunc.onFlag;
        if(lOnFlag == 0) break;
        if(i == lFuncId) {
            char* lName = lTestFunc.name;
            GTEST_FUNC lFunction = lTestFunc.func;
            printf("//===============================================\n");
            printf("//### %s\n", lName);
            printf("//===============================================\n");
            printf("Execution...\n");
            lFunction();
            break;
        }
        i++;
    }
}
//===============================================
static void GOpenCVImage_RunLast() {
    int i = 0;
    sGTestFunc lLastFunc = GTEST_FUNC_MAP[0];
    while(1) {
        sGTestFunc lTestFunc = GTEST_FUNC_MAP[i];
        int lOnFlag = lTestFunc.onFlag;
        if(lOnFlag == 0) {
            char* lName = lLastFunc.name;
            GTEST_FUNC lFunction = lLastFunc.func;
            printf("//===============================================\n");
            printf("//### %s\n", lName);
            printf("//===============================================\n");
            printf("Execution...\n");
            lFunction();
            break;
        }
        lLastFunc = lTestFunc;
        i++;
    }
}
//===============================================
static void GOpenCVImage_RunAll() {
    int i = 0;
    while(1) {
        sGTestFunc lTestFunc = GTEST_FUNC_MAP[i];
        int lOnFlag = lTestFunc.onFlag;
        if(lOnFlag == 0) break;
        char* lName = lTestFunc.name;
        GTEST_FUNC lFunction = lTestFunc.func;
        printf("//===============================================\n");
        printf("//### %s\n", lName);
        printf("//===============================================\n");
        printf("Execution...\n");
        lFunction();
        i++;
    }
}
//===============================================
static void GOpenCVImage_Load() {
    GImage()->Load("LENA", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->Load("FRUITS", "./data/img/fruits.jpg", CV_LOAD_IMAGE_COLOR);
    GWindow()->Create("LENA", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("FRUITS", CV_WINDOW_AUTOSIZE);
    GImage()->Show("LENA", "LENA");
    GImage()->Show("FRUITS", "FRUITS");
    GEvent()->Loop();
    GImage()->Remove("LENA");
    GImage()->Remove("FRUITS");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Gray() {
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateGray("IMAGE", "GRAY");
    GImage()->Gray("IMAGE", "GRAY");
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("GRAY", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("GRAY", "GRAY");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("GRAY");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Smooth() {
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "SMOOTH");
    GImage()->Smooth("IMAGE", "SMOOTH");
    GImage()->Smooth("SMOOTH", "SMOOTH");
    GImage()->Smooth("SMOOTH", "SMOOTH");
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("SMOOTH", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("SMOOTH", "SMOOTH");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("SMOOTH");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Canny() {
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateGray("IMAGE", "CANNY");
    GImage()->Gray("IMAGE", "CANNY");
    GImage()->Canny("CANNY", "CANNY", 10, 100, 3);
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("CANNY", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("CANNY", "CANNY");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("CANNY");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_PyrDown() {
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateHalf("IMAGE", "PYRDOWN");
    GImage()->CreateHalf("PYRDOWN", "PYRDOWN_2");
    GImage()->PyrDown("IMAGE", "PYRDOWN");
    GImage()->PyrDown("PYRDOWN", "PYRDOWN_2");
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("PYRDOWN", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("PYRDOWN_2", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("PYRDOWN", "PYRDOWN");
    GImage()->Show("PYRDOWN_2", "PYRDOWN_2");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("PYRDOWN");
    GImage()->Remove("PYRDOWN_2");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Saturate() {
    sGSaturate lSaturate = (sGSaturate){
        {1, 0}, {0, 0}, {0, 0}
    };
    sGSaturate lSaturate2 = (sGSaturate){
        {0, 0}, {1, 0}, {0, 0}
    };
    sGSaturate lSaturate3 = (sGSaturate){
        {0, 0}, {0, 0}, {1, 0}
    };

    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "SATURATE");
    GImage()->CreateParams("IMAGE", "SATURATE_2");
    GImage()->CreateParams("IMAGE", "SATURATE_3");
    GImage()->Copy("IMAGE", "SATURATE");
    GImage()->Copy("IMAGE", "SATURATE_2");
    GImage()->Copy("IMAGE", "SATURATE_3");
    GImage()->Saturate("SATURATE", &lSaturate);
    GImage()->Saturate("SATURATE_2", &lSaturate2);
    GImage()->Saturate("SATURATE_3", &lSaturate3);
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("SATURATE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("SATURATE_2", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("SATURATE_3", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("SATURATE", "SATURATE");
    GImage()->Show("SATURATE_2", "SATURATE_2");
    GImage()->Show("SATURATE_3", "SATURATE_3");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("SATURATE");
    GImage()->Remove("SATURATE_2");
    GImage()->Remove("SATURATE_3");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Roi() {
    CvRect lRoi = {
            100, 100, 200, 200
    };
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "ROI");
    GImage()->Copy("IMAGE", "ROI");
    GImage()->SetRoi("ROI", lRoi);
    GImage()->Not("ROI", "ROI");
    GImage()->ResetRoi("ROI");
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("ROI", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("ROI", "ROI");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Header() {
    CvRect lRoi = {
            150, 150, 150, 150
    };
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "ROI");
    GImage()->Copy("IMAGE", "ROI");
    GImage()->CreateHeader("ROI", "HEADER", lRoi);
    GImage()->Not("HEADER", "HEADER");
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("ROI", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("HEADER", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("ROI", "ROI");
    GImage()->Show("HEADER", "HEADER");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("ROI");
    GImage()->Remove("HEADER");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Blend() {
    CvRect lRoi = {
            150, 150, 150, 150
    };
    CvRect lRoi2 = {
            150, 150, lRoi.width, lRoi.height
    };
    sGImgWeight lImgWeight = {
            0.5, 0.9, 0.0
    };
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->Load("IMAGE_2", "./data/img/fruits.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "BLEND");
    GImage()->Copy("IMAGE", "BLEND");
    GImage()->SetRoi("BLEND", lRoi);
    GImage()->SetRoi("IMAGE_2", lRoi2);
    GImage()->AddWeight("BLEND", "IMAGE_2", "BLEND", lImgWeight);
    GImage()->ResetRoi("BLEND");
    GImage()->ResetRoi("IMAGE_2");
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("IMAGE_2", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("BLEND", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("IMAGE_2", "IMAGE_2");
    GImage()->Show("BLEND", "BLEND");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("IMAGE_2");
    GImage()->Remove("BLEND");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Rectangle() {
    sGRectangle lRect = (sGRectangle){
        {100, 100}, {300, 300},
        {{127, 0, 0, 0}},
        2, 20
    };
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "RECTANGLE");
    GImage()->Copy("IMAGE", "RECTANGLE");
    GImage()->Rectangle("RECTANGLE", lRect);
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("RECTANGLE", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("RECTANGLE", "RECTANGLE");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("RECTANGLE");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Split() {
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateGray("IMAGE", "RED");
    GImage()->CreateGray("IMAGE", "GREEN");
    GImage()->CreateGray("IMAGE", "BLUE");
    GImage()->Split("IMAGE", "RED", "GREEN", "BLUE");
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("RED", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("GREEN", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("BLUE", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("RED", "RED");
    GImage()->Show("GREEN", "GREEN");
    GImage()->Show("BLUE", "BLUE");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("RED");
    GImage()->Remove("GREEN");
    GImage()->Remove("BLUE");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Merge() {
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateGray("IMAGE", "RED");
    GImage()->CreateGray("IMAGE", "GREEN");
    GImage()->CreateGray("IMAGE", "BLUE");
    GImage()->CreateParams("IMAGE", "MERGE");
    GImage()->Split("IMAGE", "RED", "GREEN", "BLUE");
    GImage()->Merge("RED", "GREEN", "BLUE", "MERGE");
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("RED", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("GREEN", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("BLUE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("MERGE", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("RED", "RED");
    GImage()->Show("GREEN", "GREEN");
    GImage()->Show("BLUE", "BLUE");
    GImage()->Show("MERGE", "MERGE");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("RED");
    GImage()->Remove("GREEN");
    GImage()->Remove("BLUE");
    GImage()->Remove("MERGE");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_AddWeight() {
    sGImgWeight lImgWeight = (sGImgWeight){
        0.5, 0.5, 0.0
    };

    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->Load("IMAGE_2", "./data/img/fruits.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "ADD_WEIGHT");
    GImage()->AddWeight("IMAGE", "IMAGE_2", "ADD_WEIGHT", lImgWeight);
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("IMAGE_2", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("ADD_WEIGHT", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("IMAGE_2", "IMAGE_2");
    GImage()->Show("ADD_WEIGHT", "ADD_WEIGHT");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("IMAGE_2");
    GImage()->Remove("ADD_WEIGHT");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Sum() {
    sGRgbFactor lRgbFactor = (sGRgbFactor){
        7.0/9, 1.0/9, 1.0/9
    };

    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateGray("IMAGE", "RED");
    GImage()->CreateGray("IMAGE", "GREEN");
    GImage()->CreateGray("IMAGE", "BLUE");
    GImage()->CreateGray("IMAGE", "SUM");
    GImage()->Split("IMAGE", "RED", "GREEN", "BLUE");
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("RED", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("GREEN", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("BLUE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("SUM", CV_WINDOW_AUTOSIZE);
    GImage()->Sum("SUM", "RED", "GREEN", "BLUE", lRgbFactor);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("RED", "RED");
    GImage()->Show("GREEN", "GREEN");
    GImage()->Show("BLUE", "BLUE");
    GImage()->Show("SUM", "SUM");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("RED");
    GImage()->Remove("GREEN");
    GImage()->Remove("BLUE");
    GImage()->Remove("SUM");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Threshold() {
    sGThreshold lThres = (sGThreshold){
        100, 255, CV_THRESH_BINARY
    };
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateGray("IMAGE", "THRESHOLD");
    GImage()->Gray("IMAGE", "THRESHOLD");
    GImage()->Threshold("THRESHOLD", "THRESHOLD", lThres);
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("THRESHOLD", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("THRESHOLD", "THRESHOLD");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("THRESHOLD");
    GStorage()->Remove("STORAGE");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_HoughCircle() {
    sGHoughCircle lHoughCircle = (sGHoughCircle){
        CV_HOUGH_GRADIENT, 2, 100
    };
    GStorage()->CreateStore("STORAGE", 0);
    GImage()->Load("IMAGE", "./data/img/circle.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateGray("IMAGE", "GRAY");
    GImage()->CreateParams("IMAGE", "HOUGHCIRCLE");
    GImage()->Gray("IMAGE", "GRAY");
    GImage()->Copy("IMAGE", "HOUGHCIRCLE");
    GImage()->HoughCircle("GRAY", "STORAGE", lHoughCircle);
    GImage()->HoughCircleSet("HOUGHCIRCLE", "STORAGE");
    GStorage()->ShowSeqCircle("STORAGE");
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("GRAY", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("HOUGHCIRCLE", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("GRAY", "GRAY");
    GImage()->Show("HOUGHCIRCLE", "HOUGHCIRCLE");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("GRAY");
    GImage()->Remove("HOUGHCIRCLE");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_WarpAffine() {
	sGRotate2D lRotate2D = (sGRotate2D){
		{0.0, 0.0}, {0.5, 0.5}, 45.0, 0.5
	};
	sGFillFlag lFillFlag = (sGFillFlag){
		CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS,
		CV_RGB(0, 0, 50)
	};
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "WARP_AFFINE");
    GMatrix()->Create("MATRIX", 2, 3, CV_32FC1);
    GImage()->GetPointF("IMAGE", &lRotate2D.center, lRotate2D.factor);
    GMatrix()->Rotate2D("MATRIX", lRotate2D);
    GImage()->WarpAffine("IMAGE", "WARP_AFFINE", "MATRIX", lFillFlag);
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("WARP_AFFINE", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("WARP_AFFINE", "WARP_AFFINE");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("WARP_AFFINE");
    GMatrix()->Remove("MATRIX");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_WarpPerspective() {
	sGQuad lQuad = (sGQuad){
		{{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}},
		{{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}},
		{{0.0, 0.0}, {1.0, 0.0}, {0.0, 1.0}, {1.0, 1.0}},
		{{0.05, 0.33}, {0.9, 0.25}, {0.2, 0.7}, {0.8, 0.9}}
	};
	sGFillFlag lFillFlag = (sGFillFlag){
		CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS,
		CV_RGB(0, 0, 50)
	};
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "WARP_PERSPECTIVE");
    GMatrix()->Create("MATRIX", 3, 3, CV_32FC1);
    GImage()->GetQuad("IMAGE", &lQuad);
    GMatrix()->GetPerspective("MATRIX", lQuad);
    GImage()->WarpPerspective("IMAGE", "WARP_PERSPECTIVE", "MATRIX", lFillFlag);
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("WARP_PERSPECTIVE", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("WARP_PERSPECTIVE", "WARP_PERSPECTIVE");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("WARP_PERSPECTIVE");
    GMatrix()->Remove("MATRIX");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_LogPolar() {
	sGLogPolar lLogPolar = (sGLogPolar){
		{0.0, 0.0}, {1.0/4, 1.0/2}, 2.0,
		CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS
	};
	sGLogPolar lLogInverse = (sGLogPolar){
		{0.0, 0.0}, {1.0/4, 1.0/2}, 2.0,
		CV_INTER_LINEAR | CV_WARP_INVERSE_MAP
	};
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "LOG_POLAR");
    GImage()->CreateParams("IMAGE", "LOG_INVERSE");
    GImage()->GetPointF("IMAGE", &lLogPolar.center, lLogPolar.factor);
    GImage()->GetPointF("IMAGE", &lLogInverse.center, lLogPolar.factor);
    GImage()->LogPolar("IMAGE", "LOG_POLAR", lLogPolar);
    GImage()->LogPolar("LOG_POLAR", "LOG_INVERSE", lLogInverse);
    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("LOG_POLAR", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("LOG_INVERSE", CV_WINDOW_AUTOSIZE);
    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("LOG_POLAR", "LOG_POLAR");
    GImage()->Show("LOG_INVERSE", "LOG_INVERSE");
    GEvent()->Loop();
    GImage()->Remove("IMAGE");
    GImage()->Remove("LOG_POLAR");
    GImage()->Remove("LOG_INVERSE");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_DFT() {
	sGDFT lDFT = (sGDFT){
		CV_DXT_FORWARD, 0
	};
	sGDFT lDFTInv = (sGDFT){
		CV_DXT_INV_SCALE, 0
	};
	sGMinMax lMinMax = (sGMinMax){
		0.0, 0.0
	};

    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);

    GImage()->CreateImg("IMAGE", "GRAY", IPL_DEPTH_8U, 1);
    GImage()->CreateImg("GRAY", "REAL", IPL_DEPTH_64F, 1);
    GImage()->CreateImg("GRAY", "IMAG", IPL_DEPTH_64F, 1);
    GImage()->CreateImg("GRAY", "COMPLEX", IPL_DEPTH_64F, 2);
    GImage()->CreateImg("GRAY", "FOURIER", IPL_DEPTH_64F, 2);
    GImage()->CreateImg("GRAY", "MAGNITUDE", IPL_DEPTH_64F, 1);
    GImage()->CreateImg("IMAGE", "DFT", IPL_DEPTH_8U, 1);
    GImage()->CreateImg("IMAGE", "DFT_INV", IPL_DEPTH_8U, 1);

    GImage()->Gray("IMAGE", "GRAY");
    GImage()->Convert("GRAY", "REAL");
    GImage()->Zero("IMAG");
    GImage()->Merge("REAL", "IMAG", "", "COMPLEX");
    GImage()->DFT("COMPLEX", "FOURIER", lDFT);
    GImage()->Split("FOURIER", "REAL", "IMAG", "");
    GImage()->DFTMagnitude("REAL", "IMAG", "MAGNITUDE");
    GImage()->DFTCenter("MAGNITUDE");
    GImage()->MinMax("MAGNITUDE", &lMinMax);
    GImage()->ConvertScale("MAGNITUDE", "DFT", lMinMax.scale, lMinMax.shift);

    GImage()->DFT("FOURIER", "COMPLEX", lDFTInv);
    GImage()->Split("COMPLEX", "REAL", "IMAG", "");
    GImage()->DFTMagnitude("REAL", "IMAG", "MAGNITUDE");
    GImage()->MinMax("MAGNITUDE", &lMinMax);
    GImage()->ConvertScale("MAGNITUDE", "DFT_INV", lMinMax.scale, lMinMax.shift);

    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("GRAY", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("REAL", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("IMAG", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("MAGNITUDE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("DFT", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("DFT_INV", CV_WINDOW_AUTOSIZE);

    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("GRAY", "GRAY");
    GImage()->Show("REAL", "REAL");
    GImage()->Show("IMAG", "IMAG");
    GImage()->Show("MAGNITUDE", "MAGNITUDE");
    GImage()->Show("DFT", "DFT");
    GImage()->Show("DFT_INV", "DFT_INV");

    GEvent()->Loop();

    GImage()->Remove("IMAGE");
    GImage()->Remove("GRAY");
    GImage()->Remove("REAL");
    GImage()->Remove("IMAG");
    GImage()->Remove("COMPLEX");
    GImage()->Remove("FOURIER");
    GImage()->Remove("MAGNITUDE");
    GImage()->Remove("DFT");

    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVImage_Convolution() {
    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);

    GImage()->CreateGray("IMAGE", "GRAY");

    GImage()->Gray("IMAGE", "GRAY");

    GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
    GWindow()->Create("GRAY", CV_WINDOW_AUTOSIZE);

    GImage()->Show("IMAGE", "IMAGE");
    GImage()->Show("GRAY", "GRAY");

    GEvent()->Loop();

    GImage()->Remove("IMAGE");
    GImage()->Remove("GRAY");

    GWindow()->RemoveAll();
}
//===============================================
