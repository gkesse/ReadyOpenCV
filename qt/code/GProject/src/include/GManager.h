//===============================================
#ifndef _GManager_
#define _GManager_
//===============================================
#include "GInclude.h"
#include "GModule.h"
//===============================================
class GManager : public QWidget {
	Q_OBJECT

private:
	GManager();

public:
	~GManager();
	static GManager* Instance();
	bool checkModuleMax();
	void infoModuleMax(QWidget* parent);
	int incrementModuleCount();
	int incrementModuleIndex();
	void openImage(QWidget* parent, GModule* module);
	void setImage(QString fullname);
	void print();

signals:
	void emitModuleMax();
	void emitImageOpen(QString filename, GModule* module);

private:
	static GManager* m_instance;
	sGManager* mg;
};
//===============================================
#endif
//===============================================
