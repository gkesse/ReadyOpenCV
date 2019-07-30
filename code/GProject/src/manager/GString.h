//================================================
#ifndef _GString_
#define _GString_
//================================================
#include "GInclude.h"
//================================================
class GString {
private:
	GString();
	
public:
	~GString();
	static GString* Instance();
    string trimLeft(const string& str, const string& chars = "\t\n\v\f\r ");
    string trimRight(const string& str, const string& chars = "\t\n\v\f\r ");
    string trim(const string& str, const string& chars = "\t\n\v\f\r ");
    vector<string> split(const string& str, const string& delimiter);

private:
	static GString* m_instance;
};
//================================================
#endif
//================================================
