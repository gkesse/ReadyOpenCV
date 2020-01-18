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

protected:
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent *event);

public slots:
	void slotWindowPress(QPoint position);
	void slotWindowMove(QPoint position);
	void slotWindowMinimize();
	void slotWindowMaximize();
	void slotWindowFullScreen();
	void slotModuleImageAction(QString action);

private:
	QPoint m_pressPosition;
	QSizeGrip* m_sizeGrip;
	QPixmap* m_shape;
};
//===============================================
#endif
//===============================================
