//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include "GInclude.h"
//===============================================
class GWindow : public QWidget {
	Q_OBJECT

public:
	GWindow(QWidget* parent = 0);
	virtual ~GWindow();
	static GWindow* Create(QString key);

public slots:
	virtual void slotWindowPress(QPoint position) = 0;
	virtual void slotWindowMove(QPoint position) = 0;
	virtual void slotWindowMinimize() = 0;
	virtual void slotWindowMaximize() = 0;
	virtual void slotWindowFullScreen() = 0;

signals:
	void emitWindowMaximize(int state);
};
//===============================================
#endif
//===============================================
