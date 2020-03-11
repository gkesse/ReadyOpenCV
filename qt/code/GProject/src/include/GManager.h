//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
//===============================================
class GManager : public QWidget {
	Q_OBJECT

private:
	GManager();

public:
	~GManager();
	static GManager* Instance();
	QString getCurrentPath();
	bool checkModuleMax();
	void infoModuleMax(QWidget* parent);
	int incrementModuleCount();
	int incrementModuleIndex();
	int incrementImageIndex();
	sGImageItem* checkImage(int index);
	QString getActionId(int moduleIndex, QString actionKey);
	QString getActionId(int moduleIndex, QString action, int actionIndex);
	QString getTabId(int moduleIndex, int tabIndex);
	int getImageIndex();
	void setModuleMax(int moduleMax);
	void setModuleCurrentIndex(int currentIndex);
	int getModuleCurrentIndex();
	void save();
	void load();
	void print();

	signals:
	void emitModuleMax();
	void emitImageOpen(int index, QString action);

private:
	static GManager* m_instance;
	sGManager* mg;

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
