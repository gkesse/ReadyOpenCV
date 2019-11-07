//===============================================
#ifndef _GInclude_
#define _GInclude_
 //===============================================
#if defined(__WIN32)
#define G_PLATEFORM_OS "WINDOWS"
//===============================================
#define _USE_MATH_DEFINES
#define GLEW_STATIC
//===============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdarg.h>
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
#if !defined(BOOL)
#define BOOL int
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
