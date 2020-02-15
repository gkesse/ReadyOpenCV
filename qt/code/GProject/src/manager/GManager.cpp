//===============================================
#include "GManager.h"
#include "GSerialize.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
GManager::GManager() {
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
	// image
	mg->image = new sGImage;
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
	return mg->commun->current_path;
}
//===============================================
	bool GManager::checkModuleMax() {
	bool lMax = false;
	if(mg->module->count >= mg->module->max) {
		lMax = true;
		emit emitModuleMax();
	}
	return lMax;
}
//===============================================
void GManager::infoModuleMax(QWidget* parent) {
	QString lTitle = tr("Module max atteint | Readydev");
	QString lMessage = tr(""
			"Vous avez atteint le <b style='color:yellow'>nombre maximun</b> de module.<br/>"
			"Vous ne pouvez plus rajouter de module.");
	QMessageBox::warning(parent, lTitle, lMessage, QMessageBox::Ok);
}
//===============================================
int GManager::incrementModuleCount() {
	mg->module->count++;
	return mg->module->count;
}
//===============================================
int GManager::incrementModuleIndex() {
	mg->module->index++;
	return mg->module->index;
}
//===============================================
QString GManager::getActionId(int index, QString action) {
	QString lActionId = QString("%1_%2").arg(index).arg(action);
	return lActionId;
}
//===============================================
sGImageItem* GManager::checkImage(int index) {
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
	QFile lFile(mg->commun->setting_path);
	if(lFile.open(QIODevice::WriteOnly))	{
		QDataStream lOut(&lFile);
		lOut << *mg;
		lFile.close();
	}
}
//===============================================
void GManager::load() {
	QFile lFile(mg->commun->setting_path);
	if(lFile.open(QIODevice::ReadOnly))	{
		QDataStream lIn(&lFile);
		lIn >> mg;
		lFile.close();
	}
}
//===============================================
void GManager::print() {
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
