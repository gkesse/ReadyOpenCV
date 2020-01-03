//===============================================
#include "GModule.h"
#include "GModuleImage.h"
#include "GModuleVideo.h"
//===============================================
GModule::GModule(QWidget* parent) :
QWidget(parent) {
	setObjectName("GModule");
}
//===============================================
GModule::~GModule() {

}
//===============================================
GModule* GModule::Create(QString key) {
	if(key == "IMAGE") return new GModuleImage;
	if(key == "VIDEO") return new GModuleVideo;
	return new GModuleImage;
}
//===============================================
