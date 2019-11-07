//===============================================
#include "GProcess.h"
#include "GProcessTest.h"
#include "GProcessImageLoad.h"
#include "GProcessVideoRead.h"
#include "GProcessTrackbar.h"
#include "GConfig.h"
//===============================================
GProcess* GProcess::m_instance = 0;
//===============================================
GProcess::GProcess() {

}
//===============================================
GProcess::~GProcess() {

}
//===============================================
GProcess* GProcess::Instance() {
    string lKey = GConfig::Instance()->getData("PROCESS");
    if(lKey == "TEST") return GProcessTest::Instance();
    if(lKey == "IMAGE_LOAD") return GProcessImageLoad::Instance();
    if(lKey == "VIDEO_READ") return GProcessVideoRead::Instance();
    if(lKey == "TRACKBAR") return GProcessVideoRead::Instance();
    return GProcessTest::Instance();
}
//===============================================
