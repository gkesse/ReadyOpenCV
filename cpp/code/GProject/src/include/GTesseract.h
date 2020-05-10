//================================================
#ifndef _GTesseract_
#define _GTesseract_
//================================================
#include "GInclude.h"
//================================================
#if defined(_GUSE_TESSERACT_ON_)
//================================================
class GTesseract {
private:
    GTesseract();

public:
    ~GTesseract();
    static GTesseract* Instance();
    void test(int argc, char** argv);
    // tesseract
    void createTesseract(std::string tesseractId, std::string language);
    void setImageOpenCV(std::string tesseractId, std::string imgId);
    std::string getString(std::string tesseractId);
    void deleteTesseract(std::string tesseractId);

private:
    const char* __CLASSNAME__;
    static GTesseract* m_instance;
    std::map<std::string, tesseract::TessBaseAPI*> m_tesseractMap;
};
//===============================================
#endif
//===============================================
#endif
//================================================
