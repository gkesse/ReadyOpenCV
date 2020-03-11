//===============================================
#ifndef _GDialog_
#define _GDialog_
//===============================================
#include "GInclude.h"
#include "GRow.h"
//===============================================
class GDialog : public QDialog {
	Q_OBJECT

public:
	GDialog(QWidget* parent = 0);
	virtual ~GDialog();
	static GDialog* Create(QString key, QWidget* parent = 0);
	QString getConvertType();

public slots:
	virtual void slotWindowPress(QPoint position);
	virtual void slotWindowMove(QPoint position);

protected:
	QVBoxLayout* m_frameLayout;
	QHBoxLayout* m_buttonMapLayout;
	QPoint m_pressPosition;
	GRow* m_convertType;

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
