//===============================================
#ifndef _GInclude_
#define _GInclude_
//===============================================
#if defined(__unix)
//===============================================
#define _D_GNU_SOURCE
#define _USE_MATH_DEFINES
//===============================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <ctime>
#include <fstream>
#include <sstream>
//===============================================
#define _GUSE_OPENCV_ON_
#define _GUSE_TESSERACT_ON_
#define _GUSE_ZBAR_ON_
//===============================================
#if defined(_GUSE_OPENCV_ON_)
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#endif
//===============================================
#if defined(_GUSE_TESSERACT_ON_)
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#endif
//===============================================
#if defined(_GUSE_ZBAR_ON_)
#include <zbar.h>
#endif
//===============================================
#endif
//===============================================
#if defined(__WIN32)
//===============================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstd::string>
#include <cstdarg>
#include <ctime>
//===============================================
using namespace std;
//===============================================
#endif
//===============================================
#include "GStruct.h"
//===============================================
#endif
//===============================================
