//===============================================
#include "GProcess.h"
#include "GProcessTest.h"
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
    return GProcessTest::Instance();
}
//===============================================
