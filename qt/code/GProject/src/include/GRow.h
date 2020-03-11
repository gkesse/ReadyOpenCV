//===============================================
#ifndef _GRow_
#define _GRow_
//===============================================
#include "GInclude.h"
//===============================================
class GRow : public QFrame {
	Q_OBJECT

public:
	GRow(QWidget* parent = 0);
	virtual ~GRow();
	static GRow* Create(QString key);

public:
	virtual void setTextLabel(QString text);
	virtual QString getTextLineEdit();
	virtual void clearComboBox();
	virtual void addDataComboBox(QString text);
	virtual void addDataComboBox(QStringList text);
	virtual QString getDataComboBox();

public slots:
	virtual void slotWindowBrowser();

signals:
	void emitWindowBrowser();

protected:
	QLabel* m_label;
	QLineEdit* m_lineEdit;
	QToolButton* m_browser;
	QComboBox* m_comboBox;

private:
	const char* __CLASSNAME__;
};
//===============================================
#endif
//===============================================
