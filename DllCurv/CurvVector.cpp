#include "stdafx.h"
#include "CurvVector.h"
#include <cmath>

CurvVector::CurvVector(void)
{
}


CurvVector::~CurvVector(void)
{
}

void CurvVector::CalcLong() {
	//рассчет длинны вектора
	double x=_end._x-_begin._x;
	double y=_end._y-_begin._y;
	double z=_end._z-_begin._z;
	_l=sqrt(x*x+y*y+z*z);
}
