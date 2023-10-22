#include "stdafx.h"
#include "CurvSplineSpiral.h"
#include <cmath>
using namespace std;


CurvSplineSpiral::CurvSplineSpiral(double r)
{
	_r=r;
	_centr._x=_centr._y=_centr._z=0;
}


CurvSplineSpiral::~CurvSplineSpiral(void)
{
}

CurvDPoint CurvSplineSpiral::GetPoint(double t) {
	//возвращает т очку на окружности
	CurvDPoint ret;
	ret._x=_r*std::cos(t)+_centr._x;
	ret._y=_r*std::sin(t)+_centr._y;
	//исходя из условия
	//. any point on helix satisfies the condition C(t + 2*PI) = C(t) + {0, 0, step}
	ret._z=t+_centr._z;
	return ret;
}
CurvVector CurvSplineSpiral::GetVector(double t) {
	CurvVector ret;
	ret._begin=GetPoint(t);
	ret._end=GetPoint(t);
	ret.CalcLong();
	return ret;
}
