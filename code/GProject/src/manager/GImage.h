//================================================
#ifndef _GImage_
#define _GImage_
//================================================
#include "GInclude.h"
//================================================
class GImage {
private:
	GImage();
	
public:
	~GImage();
	static GImage* Instance();
    void read(const string& imageName, const string& file, const int& flags);
    void show(const string& imageName, const string& windowName);

private:
	static GImage* m_instance;
    map<string, cv::Mat> m_imgMap;
};
//================================================
#endif
//================================================
