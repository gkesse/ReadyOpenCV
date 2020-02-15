//===============================================
#include "GWorkspaceItem.h"
#include "GWorkspaceItemImage.h"
#include "GWorkspaceItemVideo.h"
#include "GImage.h"
//===============================================
GWorkspaceItem::GWorkspaceItem(QWidget* parent) :
QFrame(parent) {
	setObjectName("GWorkspaceItem");
	m_workspace = 0;
	m_scrollArea = 0;
	m_image = 0;
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
void GWorkspaceItem::setImage(int index, QString action) {
	delete m_image;
	m_image = GImage::Instance()->convertImage(index, action);
	m_workspace->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	m_workspace->setScaledContents(true);
	m_workspace->setPixmap(QPixmap::fromImage(*m_image));
	m_workspace->adjustSize();
	m_scrollArea->setWidgetResizable(false);
	GImage::Instance()->deleteQImage();
}
//===============================================
