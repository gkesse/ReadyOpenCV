//===============================================
#ifndef _GSection_
#define _GSection_
//===============================================
#include "GInclude.h"
//===============================================
class GSection : public QFrame {
public:
	GSection(QWidget* parent = 0);
	virtual ~GSection();
	static GSection* Create(QString key);
};
//===============================================
#endif
//===============================================
