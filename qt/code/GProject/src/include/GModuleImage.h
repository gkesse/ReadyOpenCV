//===============================================
#ifndef _GModuleImage_
#define _GModuleImage_
//===============================================
#include "GModule.h"
//===============================================
class GModuleImage : public GModule {
public:
	GModuleImage(QWidget* parent = 0);
	~GModuleImage();

protected:
	void mousePressEvent(QMouseEvent *event);

public slots:
	void slotModuleMenuSelect(QAction* action);

private:
	QMenu* m_moduleMenu;
	QMap<QAction*, QString> m_actionMap;
};
//===============================================
#endif
//===============================================
