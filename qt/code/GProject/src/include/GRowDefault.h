//===============================================
#ifndef _GRowDefault_
#define _GRowDefault_
//===============================================
#include "GRow.h"
//===============================================
class GRowDefault : public GRow {
public:
	GRowDefault(QWidget* parent = 0);
	~GRowDefault();

public:
	void setLabelText(QString text);
	QString getFieldText();

private:
	QLabel* m_label;
	QLineEdit* m_field;
};
//===============================================
#endif
//===============================================
