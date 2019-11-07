//================================================
#ifndef _GVideo_
#define _GVideo_
//================================================
#include "GInclude.h"
//================================================
class GVideo {
private:
	GVideo();
	
public:
	~GVideo();
	static GVideo* Instance();
	void open(const string& videoName, const string& file);
	void setImage(const string& videoName, const string& imageName);

private:
	static GVideo* m_instance;
	map<string, cv::VideoCapture> m_videoMap;
};
//================================================
#endif
//================================================
