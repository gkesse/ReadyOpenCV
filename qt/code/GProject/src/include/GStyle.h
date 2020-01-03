//===============================================
#ifndef _GStyle_
#define _GStyle_
//===============================================
#include "GInclude.h"
//===============================================
class GStyle {
private:
	GStyle();

public:
	~GStyle();
	static GStyle* Instance();
	void load(QString filename);

private:
	static GStyle* m_instance;
};
//===============================================
#endif
//===============================================
