//===============================================
#ifndef _GModule_
#define _GModule_
//===============================================
#include "GInclude.h"
//===============================================
class GModule : public QFrame {
	Q_OBJECT

public:
	GModule(QWidget* parent = 0);
	virtual ~GModule();
	static GModule* Create(QString key);
	void setIndex(int index);
	void setTitle(int index);
	int getIndex();
	void initCurrentStatus();
	void setCurrentStatus();
	void setModuleIndex(int moduleIndex);
	void setPropertyData(QString key, QString value);

protected:
	void mousePressEvent(QMouseEvent *event);

public slots:
	virtual void slotModuleCheck(bool check);
	virtual void slotModuleSetting();
	virtual void slotModuleMenuSelect(QAction* action);

signals:
	void emitModuleMenuAction(QString action, int index);
	void emitModuleCurrent(int index);

protected:
	int m_index;
	QLabel* m_title;
	QMenu* m_moduleMenu;
	QLabel* m_moduleIndex;
	QMap<QAction*, QString> m_actionMap;
	QMap<QString, QString> m_propertyMap;

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
