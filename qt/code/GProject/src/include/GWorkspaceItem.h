//===============================================
#ifndef _GWorkspaceItem_
#define _GWorkspaceItem_
//===============================================
#include "GInclude.h"
//===============================================
class GWorkspaceItem : public QFrame {
	Q_OBJECT

public:
	GWorkspaceItem(QWidget* parent = 0);
	virtual ~GWorkspaceItem();
	static GWorkspaceItem* Create(QString key);

public:
	virtual void setTitle(int index);
	virtual void setImage(QString filename);

protected:
	QLabel* m_workspace;
};
//===============================================
#endif
//===============================================
