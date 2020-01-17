//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include "GInclude.h"
//===============================================
class GWindow : public QFrame {
	Q_OBJECT

public:
	GWindow(QWidget* parent = 0);
	virtual ~GWindow();
	static GWindow* Create(QString key);

public slots:
	virtual void slotWindowPress(QPoint position);
	virtual void slotWindowMove(QPoint position);
	virtual void slotWindowMinimize();
	virtual void slotWindowMaximize();
	virtual void slotWindowFullScreen();
	virtual void slotModuleImageAction(QString action);

signals:
	void emitWindowMaximize(int oldState, int newState);
	void emitWindowFullScreen(int oldState, int newState);
};
//===============================================
#endif
//===============================================
