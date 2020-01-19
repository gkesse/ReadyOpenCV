//===============================================
#include "GManager.h"
//===============================================
GManager* GManager::m_instance = 0;
//===============================================
GManager::GManager() {
	mg = new sGManager;
	mg->module = new sGModule;
	mg->module->index = 0;
	mg->module->count = 0;
	mg->module->max = G_MODULE_MAX;
	mg->image = new sGImage;
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

	int lOk = QMessageBox::warning(
			parent, lTitle, lMessage,
			QMessageBox::Ok);
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
void GManager::openImage(QWidget* parent) {
	QString lFilename = QFileDialog::getOpenFileName(
			parent,
			"Ouvrir une image | ReadyDev",
			QDir::currentPath(),
			"Image files (*.png *.jpg *.jpeg *.bmp)");

	if(lFilename != "") {
		GManager::Instance()->setImage(lFilename.toStdString().c_str());
		GManager::Instance()->print();
	}
}
//===============================================
void GManager::setImage(QString fullname) {
	QFileInfo lFileInfo(fullname);
	QDir lDir = lFileInfo.absoluteDir();
	sGImageItem* lImage = new sGImageItem;
	lImage->path = lDir.absolutePath();
	lImage->filename = lFileInfo.fileName();
	lImage->fullname = lFileInfo.absoluteFilePath();
	mg->image->list.append(lImage);
}
//===============================================
void GManager::print() {
	cout << "[sGManager]\n";
	cout << "[sGManager][sGImage]\n";
	for(int i = 0; i < mg->image->list.size(); i++) {
		sGImageItem* lImage = mg->image->list.at(i);
		cout << "path" << " : " << lImage->path.toStdString() << "\n";
		cout << "filename" << " : " << lImage->filename.toStdString() << "\n";
		cout << "fullname" << " : " << lImage->fullname.toStdString() << "\n";
	}
}
//===============================================
