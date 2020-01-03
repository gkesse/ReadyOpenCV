//===============================================
#include "GSection.h"
#include "GSectionDefault.h"
//===============================================
GSection::GSection(QWidget* parent) :
QWidget(parent) {
	setObjectName("GSection");
}
//===============================================
GSection::~GSection() {

}
//===============================================
GSection* GSection::Create(QString key) {
	if(key == "DEFAULT") return new GSectionDefault;
	return new GSectionDefault;
}
//===============================================
