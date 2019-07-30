//================================================
#ifndef _GSetting_
#define _GSetting_
//================================================
#include "GInclude.h"
//================================================
class GSetting {
private:
    GSetting();
    
public:
    ~GSetting();
    static GSetting* Instance();
    void load(const std::string& file);

private:
    static GSetting* m_instance;
};
//================================================
#endif
//================================================
