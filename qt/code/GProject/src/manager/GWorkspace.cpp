//===============================================
#include "GWorkspace.h"
#include "GWorkspaceDefault.h"
//===============================================
GWorkspace::GWorkspace(QWidget* parent) :
QFrame(parent) {
	setObjectName("GWorkspace");
}
//===============================================
GWorkspace::~GWorkspace() {

}
//===============================================
GWorkspace* GWorkspace::Create(QString key) {
	if(key == "DEFAULT") return new GWorkspaceDefault;
	return new GWorkspaceDefault;
}
//===============================================
