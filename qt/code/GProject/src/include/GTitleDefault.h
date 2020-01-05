//===============================================
#ifndef _GTitleDefault_
#define _GTitleDefault_
//===============================================
#include "GTitle.h"
//===============================================
class GTitleDefault : public GTitle {
public:
	GTitleDefault(QWidget* parent = 0);
	~GTitleDefault();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);

public slots:
	void slotWindowMaximize(int oldState, int newState);
	void slotWindowFullScreen(int oldState, int newState);

private:
	QToolButton* m_maximize;
};
//===============================================
#endif
//===============================================
