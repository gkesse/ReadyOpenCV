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
	virtual void setImage(int index, QString action);

protected:
	QLabel* m_workspace;
	QScrollArea* m_scrollArea;
	QImage* m_image;
};
//===============================================
#endif
//===============================================
