//===============================================
#include "GWorkspaceItem.h"
#include "GWorkspaceItemImage.h"
#include "GWorkspaceItemVideo.h"
//===============================================
GWorkspaceItem::GWorkspaceItem(QWidget* parent) :
QFrame(parent) {
	setObjectName("GWorkspaceItem");
	m_workspace = 0;
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
void GWorkspaceItem::setTitle(int index) {
	QString lTitle = QString("%1 %2").arg(m_workspace->text()).arg(index);
	m_workspace->setText(lTitle);
}
//===============================================
void GWorkspaceItem::setImage(QString filename) {
	m_workspace->setPixmap(QPixmap(filename));
}
//===============================================
