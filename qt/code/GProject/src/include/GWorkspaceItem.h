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
};
//===============================================
#endif
//===============================================
