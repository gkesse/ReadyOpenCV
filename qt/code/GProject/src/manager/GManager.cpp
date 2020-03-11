//===============================================
#include "GManager.h"
#include "GSerialize.h"
#include "GDebug.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
GManager::GManager() {
	__CLASSNAME__ = __FUNCTION__;
	mg = new sGManager;
	// commun
	mg->commun = new sGCommon;
	mg->commun->setting_path = G_SETTING_PATH;
	mg->commun->current_path = QDir::currentPath();
	// module
	mg->module = new sGModule;
	mg->module->index = 0;
	mg->module->count = 0;
	mg->module->max = G_MODULE_MAX;
	mg->module->current_index = 0;
	// image
	mg->image = new sGImage;
	mg->image->index = 0;
	mg->image->count = 0;
	// video
	mg->video = new sGVideo;
	// load
	load();
}
//===============================================
GManager::~GManager() {

}
//===============================================
GManager* GManager::Instance() {
	if(m_instance == 0) {
		m_instance = new GManager;
	}
	return m_instance;
}
//===============================================
QString GManager::getCurrentPath() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	return mg->commun->current_path;
}
//===============================================
bool GManager::checkModuleMax() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	bool lMax = false;
	if(mg->module->count >= mg->module->max) {
		lMax = true;
		emit emitModuleMax();
	}
	return lMax;
}
//===============================================
void GManager::infoModuleMax(QWidget* parent) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lTitle = tr("Module max atteint | Readydev");
	QString lMessage = tr(""
			"Vous avez atteint le <b style='color:yellow'>nombre maximun</b> de module.<br/>"
			"Vous ne pouvez plus rajouter de module.");
	QMessageBox::warning(parent, lTitle, lMessage, QMessageBox::Ok);
}
//===============================================
int GManager::incrementModuleCount() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	mg->module->count++;
	return mg->module->count;
}
//===============================================
int GManager::incrementModuleIndex() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	mg->module->index++;
	return mg->module->index;
}
//===============================================
int GManager::incrementImageIndex() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	mg->image->index++;
	return mg->image->index;
}
//===============================================
QString GManager::getActionId(int moduleIndex, QString actionKey) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lActionId = QString("%1_%2").arg(moduleIndex).arg(actionKey);
	return lActionId;
}
//===============================================
QString GManager::getActionId(int moduleIndex, QString actionKey, int actionIndex) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lActionId = QString("%1_%2_%3").arg(moduleIndex).arg(actionKey).arg(actionIndex);
	return lActionId;
}
//===============================================
QString GManager::getTabId(int moduleIndex, int tabIndex) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QString lTabId = QString("%1_%2").arg(moduleIndex).arg(tabIndex);
	return lTabId;
}
//===============================================
int GManager::getImageIndex() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	return mg->image->index;
}
//===============================================
sGImageItem* GManager::checkImage(int index) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	sGImageItem* lImageItem = 0;
	for(int i = 0; i < mg->image->list.size(); i++) {
		lImageItem = mg->image->list.at(i);
		int lIndex = lImageItem->index;
		if(lIndex == index) return lImageItem;
	}
	return 0;
}
//===============================================
void GManager::save() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QFile lFile(mg->commun->setting_path);
	if(lFile.open(QIODevice::WriteOnly))	{
		QDataStream lOut(&lFile);
		lOut << *mg;
		lFile.close();
	}
}
//===============================================
void GManager::setModuleMax(int moduleMax) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	mg->module->max = moduleMax;
}
//===============================================
void GManager::setModuleCurrentIndex(int currentIndex) {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	mg->module->current_index = currentIndex;
}
//===============================================
int GManager::getModuleCurrentIndex() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	return mg->module->current_index;
}
//===============================================
void GManager::load() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	QFile lFile(mg->commun->setting_path);
	if(lFile.open(QIODevice::ReadOnly))	{
		QDataStream lIn(&lFile);
		lIn >> mg;
		lFile.close();
	}
}
//===============================================
void GManager::print() {
	GDebug::Instance()->write("%s::%s()", __CLASSNAME__, __FUNCTION__);
	cout << "-------------------------------------------------\n";
	cout << "[sGManager]\n";
	cout << "-------------------------------------------------\n";
	cout << G_VAR_NAME(mg->commun->current_path) << " : " << mg->commun->current_path.toStdString() << "\n";
	cout << G_VAR_NAME(mg->commun->setting_path) << " : " << mg->commun->setting_path.toStdString() << "\n";
	cout << "-------------------------------------------------\n";
	cout << G_VAR_NAME(mg->module->count) << " : " << mg->module->count << "\n";
	cout << G_VAR_NAME(mg->module->index) << " : " << mg->module->index << "\n";
	cout << G_VAR_NAME(mg->module->max) << " : " << mg->module->max << "\n";
	cout << "-------------------------------------------------\n";
	cout << G_VAR_NAME(mg->image->count) << " : " << mg->image->count << "\n";
	cout << "\n";
	for(int i = 0; i < mg->image->list.size(); i++) {
		sGImageItem* lImageItem = mg->image->list.at(i);
		if(i != 0) {cout << "\n";}
		cout << "mg->image->list.at(" << i <<")->path" << " : " << lImageItem->path.toStdString() << "\n";
		cout << "mg->image->list.at(" << i <<")->filename" << " : " << lImageItem->filename.toStdString() << "\n";
		cout << "mg->image->list.at(" << i <<")->fullname" << " : " << lImageItem->fullname.toStdString() << "\n";
		cout << "mg->image->list.at(" << i <<")->index" << " : " << lImageItem->index << "\n";
	}
}
//===============================================
