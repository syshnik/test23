// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
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
#define EXPORT_OR_IMPPORT OK_IMPORT

#include "../DllCurv/CurvDPoint.h"
#include "../DllCurv/CurvVector.h"
#include "../DllCurv/CurvSpline.h"

#include "../DllCurv/CurvSplineCircl.h"
#include "../DllCurv/CurvSplineEllipse.h"
#include "../DllCurv/CurvSplineSpiral.h"
