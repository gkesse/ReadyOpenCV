//===============================================
#include "GOpenCVEvent.h"
#include "GImage.h"
#include "GWindow.h"
#include "GEvent.h"
#include "GEvent.h"
#include "GConfig.h"
#include "GString2.h"
//===============================================
static GOpenCVEventO* m_GOpenCVEventO = 0;
//===============================================
static void GOpenCVEvent_Run();
static void GOpenCVEvent_RunNumber();
static void GOpenCVEvent_RunFunc();
static void GOpenCVEvent_RunLast();
static void GOpenCVEvent_RunAll();
//===============================================
static void GOpenCVEvent_Execute();
static void GOpenCVEvent_Update(void* params);
//===============================================
#define GDEFINE_TEST_FUNC(GFUNC) {1, #GFUNC, GFUNC}
#define GDEFINE_TEST_FUNC_LAST {0, 0, 0}
//===============================================
typedef void (*GTEST_FUNC)();
//===============================================
static sGTestFunc GTEST_FUNC_MAP[] = {
        GDEFINE_TEST_FUNC(GOpenCVEvent_Execute),
        GDEFINE_TEST_FUNC_LAST
};
//===============================================
GOpenCVEventO* GOpenCVEvent_New() {
    GOpenCVEventO* lObj = (GOpenCVEventO*)malloc(sizeof(GOpenCVEventO));
    lObj->m_continue = TRUE;
    lObj->Delete = GOpenCVEvent_Delete;
    lObj->Run = GOpenCVEvent_Run;
    return lObj;
}
//===============================================
void GOpenCVEvent_Delete() {
    GOpenCVEventO* lObj = GOpenCVEvent();
    if(lObj != 0) {
        free(lObj);
    }
    m_GOpenCVEventO = 0;
}
//===============================================
GOpenCVEventO* GOpenCVEvent() {
    if(m_GOpenCVEventO == 0) {
        m_GOpenCVEventO = GOpenCVEvent_New();
    }
    return m_GOpenCVEventO;
}
//===============================================
static void GOpenCVEvent_Run() {
    char* lOption1 = GConfig()->GetData("OPTION_1");
    if(GString2()->IsEqual(lOption1, "")) GOpenCVEvent_RunNumber();
    else if(GString2()->IsEqual(lOption1, "-1")) GOpenCVEvent_RunNumber();
    else if(GString2()->IsEqual(lOption1, "-2")) GOpenCVEvent_RunLast();
    else if(GString2()->IsEqual(lOption1, "-3")) GOpenCVEvent_RunAll();
    else GOpenCVEvent_RunFunc();
}
//===============================================
static void GOpenCVEvent_RunNumber() {
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
static void GOpenCVEvent_RunFunc() {
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
static void GOpenCVEvent_RunLast() {
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
static void GOpenCVEvent_RunAll() {
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
static void GOpenCVEvent_Execute() {
    sGRectangle lRect = (sGRectangle){
        {0, 0}, {0, 0},
        CV_RGB(100, 0, 0),
        -1, 20
    };

    GImage()->Load("IMAGE", "./data/img/lena.jpg", CV_LOAD_IMAGE_COLOR);
    GImage()->CreateParams("IMAGE", "COPY");

    GWindow()->Create("WINDOW", CV_WINDOW_AUTOSIZE);

    GEvent()->Init();

    while(1) {
        GEvent()->PollEvents();
        if(GEvent()->Close() == TRUE) break;
        GImage()->Copy("IMAGE", "COPY");
        GOpenCVEvent_Update(&lRect);
        GImage()->Rectangle("COPY", lRect);
        GImage()->Show("COPY", "WINDOW");
        GEvent()->Clean();
    }

    GImage()->Remove("IMAGE");
    GWindow()->RemoveAll();
}
//===============================================
static void GOpenCVEvent_Update(void* params) {
    sGEvent* lEvent = GEvent()->GetEvent();
    sGEventMouse* lMouseEvent = &lEvent->mouse;
    sGRectangle* lRect = (sGRectangle*)params;

    if(lMouseEvent->onFlag == TRUE) {
        int lX = lMouseEvent->x;
        int lY = lMouseEvent->y;
        int lX1 = lX - lRect->radius;
        int lY1 = lY - lRect->radius;
        int lX2 = lX + lRect->radius;
        int lY2 = lY + lRect->radius;
        lRect->pt1 = (CvPoint){lX1, lY1};
        lRect->pt2 = (CvPoint){lX2, lY2};
    }
}
//===============================================
