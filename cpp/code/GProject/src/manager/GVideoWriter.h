//================================================
#ifndef _GVideoWriter_
#define _GVideoWriter_
//================================================
#include "GInclude.h"
//================================================
class GVideoWriter {
private:
	GVideoWriter();
	
public:
	~GVideoWriter();
	static GVideoWriter* Instance();
	int waitKey(const int& delay);

private:
	static GVideoWriter* m_instance;
};
//================================================
#endif
//================================================
