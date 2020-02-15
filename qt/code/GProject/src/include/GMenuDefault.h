//===============================================
#ifndef _GMenuDefault_
#define _GMenuDefault_
//===============================================
#include "GMenu.h"
//===============================================
class GMenuDefault : public GMenu {
public:
	GMenuDefault(QWidget* parent = 0);
	~GMenuDefault();

private:
	void createAddModuleMenu();
	void createSettingMenu();
};
//===============================================
#endif
//===============================================
