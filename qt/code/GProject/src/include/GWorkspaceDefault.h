//===============================================
#ifndef _GWorkspaceDefault_
#define _GWorkspaceDefault_
//===============================================
#include "GWorkspace.h"
//===============================================
class GWorkspaceDefault : public GWorkspace {
public:
	GWorkspaceDefault(QWidget* parent = 0);
	~GWorkspaceDefault();

public slots:
	void slotAddModuleMenuSelect(QString module);

private:
	QStackedWidget* m_workspace;
};
//===============================================
#endif
//===============================================
