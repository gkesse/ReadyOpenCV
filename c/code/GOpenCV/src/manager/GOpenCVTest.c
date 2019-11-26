//===============================================
#include "GOpenCVTest.h"
#include "GImage.h"
#include "GWindow.h"
#include "GEvent.h"
#include "GEvent.h"
#include "GConfig.h"
#include "GString2.h"
//===============================================
static GOpenCVTestO* m_GOpenCVTestO = 0;
//===============================================
static void GOpenCVTest_Run();
static void GOpenCVTest_RunNumber();
static void GOpenCVTest_RunFunc();
static void GOpenCVTest_RunLast();
static void GOpenCVTest_RunAll();
//===============================================
static void GOpenCVTest_ImageLoad();
static void GOpenCVTest_ImageGray();
static void GOpenCVTest_ImageSmooth();
static void GOpenCVTest_ImageCanny();
static void GOpenCVTest_ImagePyrDown();
static void GOpenCVTest_ImageSaturate();
static void GOpenCVTest_ImageRoi();
static void GOpenCVTest_ImageHeader();
static void GOpenCVTest_ImageBlend();
//===============================================
#define GDEFINE_TEST_FUNC(GFUNC) {1, #GFUNC, GFUNC}
#define GDEFINE_TEST_FUNC_LAST {0, 0, 0}
//===============================================
typedef void (*GTEST_FUNC)();
//===============================================
static sGTestFunc GTEST_FUNC_MAP[] = {
		GDEFINE_TEST_FUNC(GOpenCVTest_ImageLoad),
		GDEFINE_TEST_FUNC(GOpenCVTest_ImageGray),
		GDEFINE_TEST_FUNC(GOpenCVTest_ImageSmooth),
		GDEFINE_TEST_FUNC(GOpenCVTest_ImageCanny),
		GDEFINE_TEST_FUNC(GOpenCVTest_ImagePyrDown),
		GDEFINE_TEST_FUNC(GOpenCVTest_ImageSaturate),
		GDEFINE_TEST_FUNC(GOpenCVTest_ImageRoi),
		GDEFINE_TEST_FUNC(GOpenCVTest_ImageHeader),
		GDEFINE_TEST_FUNC(GOpenCVTest_ImageBlend),
		GDEFINE_TEST_FUNC_LAST
};
//===============================================
GOpenCVTestO* GOpenCVTest_New() {
	GOpenCVTestO* lObj = (GOpenCVTestO*)malloc(sizeof(GOpenCVTestO));
	lObj->m_continue = TRUE;
	lObj->Delete = GOpenCVTest_Delete;
	lObj->Run = GOpenCVTest_Run;
	return lObj;
}
//===============================================
void GOpenCVTest_Delete() {
	GOpenCVTestO* lObj = GOpenCVTest();
	if(lObj != 0) {
		free(lObj);
	}
	m_GOpenCVTestO = 0;
}
//===============================================
GOpenCVTestO* GOpenCVTest() {
	if(m_GOpenCVTestO == 0) {
		m_GOpenCVTestO = GOpenCVTest_New();
	}
	return m_GOpenCVTestO;
}
//===============================================
static void GOpenCVTest_Run() {
	char* lOption1 = GConfig()->GetData("OPTION_1");
	if(GString2()->IsEqual(lOption1, "")) GOpenCVTest_RunNumber();
	else if(GString2()->IsEqual(lOption1, "0")) GOpenCVTest_RunNumber();
	else if(GString2()->IsEqual(lOption1, "-1")) GOpenCVTest_RunLast();
	else if(GString2()->IsEqual(lOption1, "-2")) GOpenCVTest_RunAll();
	else GOpenCVTest_RunFunc();
}
//===============================================
static void GOpenCVTest_RunNumber() {
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
static void GOpenCVTest_RunFunc() {
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
static void GOpenCVTest_RunLast() {
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
static void GOpenCVTest_RunAll() {
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
static void GOpenCVTest_ImageLoad() {
	GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
	GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
	GImage()->Show("IMAGE", "IMAGE");
	GEvent()->Loop();
	GImage()->Remove("IMAGE");
	GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVTest_ImageGray() {
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
static void GOpenCVTest_ImageSmooth() {
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
static void GOpenCVTest_ImageCanny() {
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
static void GOpenCVTest_ImagePyrDown() {
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
static void GOpenCVTest_ImageSaturate() {
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
static void GOpenCVTest_ImageRoi() {
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
static void GOpenCVTest_ImageHeader() {
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
	GImage()->Show("HEADER", "HEADER");
	GImage()->Show("ROI", "ROI");
	GEvent()->Loop();
	GImage()->Remove("IMAGE");
	GImage()->Remove("HEADER");
	GImage()->Remove("ROI");
	GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVTest_ImageBlend() {
	CvRect lRoi = {
			150, 150, 150, 150
	};
	CvRect lRoi2 = {
			150, 150, lRoi.width, lRoi.height
	};
	sGImgWeight lImgWeight = {
			0.5, 0.7, 0.0
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
