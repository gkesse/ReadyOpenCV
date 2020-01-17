//===============================================
#ifndef _GTitleDialog_
#define _GTitleDialog_
//===============================================
#include "GTitle.h"
//===============================================
class GTitleDialog : public GTitle {
public:
	GTitleDialog(QWidget* parent = 0);
	~GTitleDialog();

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);

public slots:
	void slotWindowTitleChange(QString);
	void slotWindowIconChange(QIcon);

private:
	QToolButton* m_icon;
	QLabel* m_title;
	QToolButton* m_help;
};
//===============================================
#endif
//===============================================
