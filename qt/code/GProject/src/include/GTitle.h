//===============================================
#ifndef _GTitle_
#define _GTitle_
//===============================================
#include "GInclude.h"
//===============================================
class GTitle : public QFrame {
	Q_OBJECT

public:
	GTitle(QWidget* parent = 0);
	virtual ~GTitle();
	static GTitle* Create(QString key);

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);

public slots:
	virtual void slotWindowTitleChange(QString title);
	virtual void slotWindowIconChange(QIcon icon);
	virtual void slotWindowMaximize(int oldState, int newState);
	virtual void slotWindowFullScreen(int oldState, int newState);

signals:
	void emitWindowPress(QPoint position);
	void emitWindowMove(QPoint position);
	void emitWindowMinimize();
	void emitWindowMaximize();
	void emitWindowClose();
	void emitWindowFullScreen();

protected:
	QToolButton* m_icon;
	QLabel* m_title;
	QToolButton* m_maximize;
};
//===============================================
#endif
//===============================================
