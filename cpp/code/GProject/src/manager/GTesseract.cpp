//===============================================
#include "GTesseract.h"
#include "GOpenCV.h"
#include "GDebug.h"
//================================================
#if defined(_GUSE_TESSERACT_ON_)
//===============================================
GTesseract* GTesseract::m_instance = 0;
//===============================================
GTesseract::GTesseract() {
    __CLASSNAME__ = __FUNCTION__;
}
//===============================================
GTesseract::~GTesseract() {

}
//===============================================
GTesseract* GTesseract::Instance() {
    if(m_instance == 0) {
        m_instance = new GTesseract;
    }
    return m_instance;
}
//===============================================
void GTesseract::test(int argc, char** argv) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
}
//===============================================
// tesseract
//===============================================
void GTesseract::createTesseract(std::string tesseractId, std::string language) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    tesseract::TessBaseAPI* lTesseract = new tesseract::TessBaseAPI();
    int lOk = lTesseract->Init(NULL, language.c_str(), tesseract::OEM_LSTM_ONLY);
    if(lOk == -1) {exit(0);}
    lTesseract->SetPageSegMode(tesseract::PSM_AUTO);
    m_tesseractMap[tesseractId] = lTesseract;
}
//===============================================
void GTesseract::setImageOpenCV(std::string tesseractId, std::string imgId, std::string dpi) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    tesseract::TessBaseAPI* lTesseract = m_tesseractMap[tesseractId];
    cv::Mat* lImg = GOpenCV::Instance()->getImage(imgId);
    lTesseract->SetImage(lImg->data, lImg->cols, lImg->rows, 3, lImg->step);
    lTesseract->SetVariable("user_defined_dpi", dpi.c_str());
}
//===============================================
std::string GTesseract::getString(std::string tesseractId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    tesseract::TessBaseAPI* lTesseract = m_tesseractMap[tesseractId];
    std::string lString = std::string(lTesseract->GetUTF8Text());;
    return lString;
}
//===============================================
void GTesseract::deleteTesseract(std::string tesseractId) {
    GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", _EOA_);
    tesseract::TessBaseAPI* lTesseract = m_tesseractMap[tesseractId];
    delete lTesseract;
    m_tesseractMap[tesseractId] = 0;
}
//===============================================
#endif
//===============================================
