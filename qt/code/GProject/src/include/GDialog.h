//===============================================
#ifndef _GDialog_
#define _GDialog_
//===============================================
#include "GInclude.h"
//===============================================
class GDialog : public QDialog {
	Q_OBJECT

public:
	GDialog(QWidget* parent = 0);
	virtual ~GDialog();
	static GDialog* Create(QString key, QWidget* parent = 0);

public slots:
	virtual void slotWindowPress(QPoint position);
	virtual void slotWindowMove(QPoint position);

protected:
	QVBoxLayout* m_frameLayout;
	QHBoxLayout* m_buttonMapLayout;
};
//===============================================
#endif
//===============================================
