//===============================================
#ifndef _GSection_
#define _GSection_
//===============================================
#include "GInclude.h"
//===============================================
class GSection : public QWidget {
public:
	GSection(QWidget* parent = 0);
	~GSection();
	static GSection* Create(QString key);
};
//===============================================
#endif
//===============================================
