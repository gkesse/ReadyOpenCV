//===============================================
#include "GWorkspaceItem.h"
#include "GWorkspaceItemImage.h"
#include "GWorkspaceItemVideo.h"
#include "GImage.h"
#include "GManager.h"
#include "GDebug.h"
//===============================================
GWorkspaceItem::GWorkspaceItem(QString key, QWidget* parent) :
QFrame(parent) {
	__CLASSNAME__ = __FUNCTION__;
	setObjectName("GWorkspaceItem");
	m_stackedWidget = 0;
	m_workspaceEmpty = 0;
	m_tabWidget = 0;
	m_moduleIndex = 0;
	m_tabIndex = 0;
	m_workspaceData = 0;
	m_WorkspaceDataCurrent = 0;
	m_moduleType = key;
}
//===============================================
GWorkspaceItem::~GWorkspaceItem() {

}
//===============================================
GWorkspaceItem* GWorkspaceItem::Create(QString key) {
	if(key == "IMAGE") return new GWorkspaceItemImage(key);
	if(key == "VIDEO") return new GWorkspaceItemVideo(key);
	return new GWorkspaceItemImage(key);
}
//===============================================
void GWorkspaceItem::setTitle(int moduleIndex) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lTitle = QString("%1 %2").arg(m_moduleName).arg(moduleIndex);
	m_workspaceEmpty->setText(lTitle);
}
//===============================================
void GWorkspaceItem::addImageTab(int moduleIndex, QString moduleAction) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QScrollArea* lScrollArea = new QScrollArea;
	lScrollArea->setWidgetResizable(false);
	lScrollArea->setAlignment(Qt::AlignCenter);

	m_workspaceData = new QLabel(tr("Image"));
	m_workspaceData->setAlignment(Qt::AlignCenter);

	lScrollArea->setWidget(m_workspaceData);

	int lActionIndex = GManager::Instance()->getImageIndex();
	QString lActionId = GManager::Instance()->getActionId(moduleIndex, moduleAction, lActionIndex);
	QString lTitle = lActionId;
	m_actionMap[lScrollArea] = lActionId;
	m_tabWidget->addTab(lScrollArea, lTitle);
	int lTabLastIndex = m_tabWidget->count() - 1;
	m_tabWidget->setCurrentIndex(lTabLastIndex);
	m_tabIndex += 1;
}
//===============================================
void GWorkspaceItem::setImage(int moduleIndex, QString moduleAction) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QImage lQImage = GImage::Instance()->convertImage(moduleIndex, moduleAction);
	addImageTab(moduleIndex, moduleAction);
	m_workspaceData->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	m_workspaceData->setScaledContents(true);
	m_workspaceData->setPixmap(QPixmap::fromImage(lQImage));
	m_workspaceData->adjustSize();
	m_stackedWidget->setCurrentIndex(1);
	m_moduleIndex = moduleIndex;
}
//===============================================
void GWorkspaceItem::setImage(QString actionId) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QImage lQImage = GImage::Instance()->convertImage(actionId);
	m_WorkspaceDataCurrent->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	m_WorkspaceDataCurrent->setScaledContents(true);
	m_WorkspaceDataCurrent->setPixmap(QPixmap::fromImage(lQImage));
	m_WorkspaceDataCurrent->adjustSize();
	m_stackedWidget->setCurrentIndex(1);
}
//===============================================
void GWorkspaceItem::setActionId() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	int lTabIndex = m_tabWidget->currentIndex();
	QScrollArea* lScrollArea = qobject_cast<QScrollArea*>(m_tabWidget->widget(lTabIndex));
	QString lActionId = m_actionMap[lScrollArea];
	GDebug::Instance()->write(3, "TAB_INDEX : ", 1, lTabIndex, 3, " : ", 3, lActionId.toStdString().c_str(), 0);
	GImage::Instance()->setImageId(lActionId);
}
//===============================================
void GWorkspaceItem::slotTabCloseRequest(int index) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QScrollArea* lScrollArea = qobject_cast<QScrollArea*>(m_tabWidget->widget(index));
	QString lActionId = m_actionMap[lScrollArea];
	m_tabWidget->removeTab(index);
	int lTabCount = m_tabWidget->count();
	if(m_moduleType == "IMAGE") GImage::Instance()->removeImage(lActionId);
	if(lTabCount == 0) m_stackedWidget->setCurrentIndex(0);
	GDebug::Instance()->write(1, lTabCount, 3, " : ", 3, m_moduleType.toStdString().c_str(), 3, " : ", 3, lActionId.toStdString().c_str(), 0);
}
//===============================================
void GWorkspaceItem::slotTabCurrentChange(int index) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QScrollArea* lScrollArea = qobject_cast<QScrollArea*>(m_tabWidget->widget(index));
	m_WorkspaceDataCurrent = qobject_cast<QLabel*>(lScrollArea->widget());
	QString lActionId = m_actionMap[lScrollArea];
	GDebug::Instance()->write(3, lActionId.toStdString().c_str(), 0);
	GImage::Instance()->setImageId(lActionId);
}
//===============================================
