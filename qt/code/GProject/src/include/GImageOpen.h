//===============================================
#ifndef _GImageOpen_
#define _GImageOpen_
//===============================================
#include "GInclude.h"
//===============================================
class GImageOpen : public QDialog {
	Q_OBJECT

public:
	GImageOpen(QWidget* parent = 0);
	~GImageOpen();

private:
	QLineEdit* m_filenameEdit;
};
//===============================================
#endif
//===============================================
