//===============================================
#ifndef _GWindowDefault_
#define _GWindowDefault_
//===============================================
#include "GWindow.h"
//===============================================
class GWindowDefault : public GWindow {
public:
	GWindowDefault(QWidget* parent = 0);
	~GWindowDefault();

public slots:
	void slotWindowPress(QPoint position);
	void slotWindowMove(QPoint position);
	void slotWindowMinimize();
	void slotWindowMaximize();
	void slotWindowFullScreen();

private:
	QPoint m_pressPosition;
};
//===============================================
#endif
//===============================================
