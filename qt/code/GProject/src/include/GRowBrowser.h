//===============================================
#ifndef _GRowBrowser_
#define _GRowBrowser_
//===============================================
#include "GRow.h"
//===============================================
class GRowBrowser : public GRow {
public:
	GRowBrowser(QWidget* parent = 0);
	~GRowBrowser();

public:
	void setLabelText(QString text);
	QString getFieldText();

public slots:
	void slotWindowBrowser();

private:
	QLabel* m_label;
	QLineEdit* m_field;
	QToolButton* m_browser;
};
//===============================================
#endif
//===============================================
