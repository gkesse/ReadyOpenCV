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
	virtual void setLabelText(QString text);
	virtual QString getFieldText();
};
//===============================================
#endif
//===============================================