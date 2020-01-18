//===============================================
#include "GWorkspaceItem.h"
#include "GWorkspaceItemImage.h"
#include "GWorkspaceItemVideo.h"
//===============================================
GWorkspaceItem::GWorkspaceItem(QWidget* parent) :
QFrame(parent) {
	setObjectName("GWorkspaceItem");
}
//===============================================
GWorkspaceItem::~GWorkspaceItem() {

}
//===============================================
GWorkspaceItem* GWorkspaceItem::Create(QString key) {
	if(key == "IMAGE") return new GWorkspaceItemImage;
	if(key == "VIDEO") return new GWorkspaceItemVideo;
	return new GWorkspaceItemImage;
}
//===============================================
