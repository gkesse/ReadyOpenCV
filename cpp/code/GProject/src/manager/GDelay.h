//================================================
#ifndef _GDelay_
#define _GDelay_
//================================================
#include "GInclude.h"
//================================================
class GDelay {
private:
	GDelay();
	
public:
	~GDelay();
	static GDelay* Instance();
	int waitKey(const int& delay);

private:
	static GDelay* m_instance;
};
//================================================
#endif
//================================================
