//================================================
#ifndef _GTrackbar_
#define _GTrackbar_
//================================================
#include "GInclude.h"
//================================================
class GTrackbar {
private:
	GTrackbar();
	
public:
	~GTrackbar();
	static GTrackbar* Instance();
	int waitKey(const int& delay);

private:
	static GTrackbar* m_instance;
};
//================================================
#endif
//================================================
