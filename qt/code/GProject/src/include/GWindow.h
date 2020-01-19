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

protected:
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent *event);

public slots:
	virtual void slotWindowPress(QPoint position);
	virtual void slotWindowMove(QPoint position);
	virtual void slotWindowMinimize();
	virtual void slotWindowMaximize();
	virtual void slotWindowFullScreen();
	virtual void slotModuleMax();
	virtual void slotModuleMenuAction(QString action);

signals:
	void emitWindowMaximize(int oldState, int newState);
	void emitWindowFullScreen(int oldState, int newState);

protected:
	QPoint m_pressPosition;
	QSizeGrip* m_sizeGrip;
	QPixmap* m_shape;
};
//===============================================
#endif
//===============================================
