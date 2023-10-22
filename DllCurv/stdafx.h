// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

//#define EXEF 1
#ifdef EXEF
	#define OK_EXPORT 
	#define OK_IMPORT 
	#define OK_EXTERN extern
#else
	#define OK_EXPORT __declspec(dllexport)
	#define OK_IMPORT __declspec(dllimport)
	#define OK_EXTERN EXPORT_OR_IMPPORT
#endif
#define EXPORT_OR_IMPPORT OK_EXPORT


#include "CurvDPoint.h"
#include "CurvVector.h"
#include "CurvSpline.h"
#include "CurvSplineCircl.h"
#include "CurvSplineEllipse.h"
#include "CurvSplineSpiral.h"
// TODO: reference additional headers your program requires here
