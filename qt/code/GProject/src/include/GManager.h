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
	sGImageItem* checkImage(int index);
	QString getActionId(int index, QString action);
	void save();
	void load();
	void print();

signals:
	void emitModuleMax();
	void emitImageOpen(int index, QString action);

private:
	static GManager* m_instance;
	sGManager* mg;
};
//===============================================
#endif
//===============================================
