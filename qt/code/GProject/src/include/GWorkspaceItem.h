//===============================================
#ifndef _GWorkspaceItem_
#define _GWorkspaceItem_
//===============================================
#include "GInclude.h"
//===============================================
class GWorkspaceItem : public QFrame {
	Q_OBJECT

public:
	GWorkspaceItem(QString key, QWidget* parent = 0);
	virtual ~GWorkspaceItem();
	static GWorkspaceItem* Create(QString key);

public:
	virtual void setTitle(int index);
	virtual void addImageTab(int moduleIndex, QString moduleAction);
	virtual void setImage(int moduleIndex, QString moduleAction);
	virtual void setImage(QString actionId);
	virtual void setActionId();

public slots:
	virtual void slotTabCloseRequest(int index);
	virtual void slotTabCurrentChange(int index);

protected:
	QStackedWidget* m_stackedWidget;
	QString m_moduleName;
	int m_moduleIndex;
	QString m_moduleType;
	QLabel* m_workspaceEmpty;
	QTabWidget* m_tabWidget;
	int m_tabIndex;
	QLabel* m_workspaceData;
	QLabel* m_WorkspaceDataCurrent;
	QMap<QScrollArea*, QString> m_actionMap;

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
