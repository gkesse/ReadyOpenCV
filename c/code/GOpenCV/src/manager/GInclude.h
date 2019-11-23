//===============================================
#ifndef _GInclude_
#define _GInclude_
 //===============================================
#if defined(__WIN32)
#define G_PLATEFORM_OS "WINDOWS"
//===============================================
#define _USE_MATH_DEFINES
//===============================================
#define G_USE_OPENCV_ON
//===============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
//===============================================
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/highgui/highgui_c.h>
//===============================================
#elif defined(__unix)
#define G_PLATEFORM_OS "UNIX"
//===============================================
#define _GNU_SOURCE
#define _USE_MATH_DEFINES
//===============================================
#endif
//===============================================
#if !defined(TRUE)
#define FALSE (0)
#define TRUE (!FALSE)
#endif
//===============================================
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long int ulint;
//===============================================
#include "GStruct.h"
//===============================================
#endif
//===============================================
