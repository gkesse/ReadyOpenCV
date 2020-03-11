//===============================================
#ifndef _GWorkspaceItemImage_
#define _GWorkspaceItemImage_
//===============================================
#include "GWorkspaceItem.h"
//===============================================
class GWorkspaceItemImage : public GWorkspaceItem {
public:
	GWorkspaceItemImage(QString key, QWidget* parent = 0);
	~GWorkspaceItemImage();

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
