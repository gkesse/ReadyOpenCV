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
//===============================================
#define _GUSE_OPENCV_ON_
#define _GUSE_TESSERACT_ON_
//===============================================
#if defined(_GUSE_OPENCV_ON_)
#include <opencv2/opencv.hpp>
#endif
//===============================================
#if defined(_GUSE_TESSERACT_ON_)
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
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
