//===============================================
#ifndef _GSection_
#define _GSection_
//===============================================
#include "GInclude.h"
//===============================================
class GSection : public QFrame {
	Q_OBJECT

public:
	GSection(QWidget* parent = 0);
	virtual ~GSection();
	static GSection* Create(QString key);
};
//===============================================
#endif
//===============================================
