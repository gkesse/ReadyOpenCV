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

public slots:
	virtual void slotWindowMaximize(int oldState, int newState) = 0;
	virtual void slotWindowFullScreen(int oldState, int newState) = 0;

signals:
	void emitWindowPress(QPoint position);
	void emitWindowMove(QPoint position);
	void emitWindowMinimize();
	void emitWindowMaximize();
	void emitWindowClose();
	void emitWindowFullScreen();
};
//===============================================
#endif
//===============================================
