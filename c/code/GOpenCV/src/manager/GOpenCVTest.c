//===============================================
#include "GOpenCVTest.h"
#include "GImage.h"
#include "GWindow.h"
#include "GWaitKey.h"
#include "GConfig.h"
#include "GString2.h"
//===============================================
static GOpenCVTestO* m_GOpenCVTestO = 0;
//===============================================
static void GOpenCVTest_Run();
static void GOpenCVTest_RunNumber();
static void GOpenCVTest_RunFunc();
//===============================================
static void GOpenCVTest_ImageLoad();
//===============================================
#define GDEFINE_TEST_FUNC(GFUNC) {1, #GFUNC, GFUNC}
#define GDEFINE_TEST_FUNC_LAST {0, 0, 0}
//===============================================
typedef void (*GTEST_FUNC)();
//===============================================
static sGTestFunc GTEST_FUNC_MAP[] = {
		GDEFINE_TEST_FUNC(GOpenCVTest_ImageLoad),
		GDEFINE_TEST_FUNC_LAST
};
//===============================================
GOpenCVTestO* GOpenCVTest_New() {
	GOpenCVTestO* lObj = (GOpenCVTestO*)malloc(sizeof(GOpenCVTestO));
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
	if(GString2()->IsEqual(lOption1, "number")) GOpenCVTest_RunNumber();
	else if(GString2()->IsEqual(lOption1, "run")) GOpenCVTest_RunFunc();
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
	char* lOption2 = GConfig()->GetData("OPTION_2");
	int lFuncId = GString2()->ToInt(lOption2);
	int i = 0;
	while(1) {
		sGTestFunc lTestFunc = GTEST_FUNC_MAP[i];
		int lOnFlag = lTestFunc.onFlag;
		if(lOnFlag == 0) break;
		if(i == lFuncId) {
			GTEST_FUNC lFunction = lTestFunc.func;
			lFunction();
			break;
		}
		i++;
	}
}
//===============================================
static void GOpenCVTest_ImageLoad() {
	GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
	GWindow()->Create("IMAGE", CV_WINDOW_AUTOSIZE);
	GImage()->Show("IMAGE", "IMAGE");
	GWaitKey()->Loop();
	GImage()->Remove("IMAGE");
	GWindow()->RemoveAll();
}
//===============================================
