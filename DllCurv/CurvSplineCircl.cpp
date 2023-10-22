#include "stdafx.h"
#include "CurvSplineCircl.h"
#include <cmath>

#define PROIZVODNAYA(R, X, X0, UP) ((UP) ? 1 : -1)\
	*\
	1/(2*sqrt(\
		R*R-(X-X0)*(X-X0)\
	))*(-(X-X0+X-X0))

CurvSplineCircl::CurvSplineCircl(double r)
{
	_r=r;
	_centr._x=_centr._y=_centr._z=0;
}


CurvSplineCircl::CurvSplineCircl(double r, double x, double y)
{
	_r=r;
	_centr._x=x;
	_centr._y=y;
	_centr._z=0;
}


CurvSplineCircl::~CurvSplineCircl(void)
{
}

double CurvSplineCircl::Proizv(double x, bool up) {
	//return 1/(2*sqrt(4-(x-2)*(x-2)))*(-(x-2+x-2));
	double x0=_centr._x;
	double ret = 1/(2*sqrt(_r*_r-(x-x0)*(x-x0)))*(-(x-x0+x-x0));
	if(!up) ret=-ret;
	return ret;
}

	
CurvDPoint CurvSplineCircl::GetPoint(double t) {
	//возвращает т очку на окружности
	//x=r*cos(t)+x0
	//y=r*sin(t)+y0
	CurvDPoint ret;
	ret._z=_centr._z;
	ret._x=_r*std::cos(t)+_centr._x;
	ret._y=_r*std::sin(t)+_centr._y;
	//
	return ret;
}
CurvVector CurvSplineCircl::GetVector(double t) {
	CurvVector ret;
	CurvDPoint p1=GetPoint(t), p2;
	bool up=(std::sin(t) >= 0);
	p2._z=0;
	p2._x=p1._x+(up ? -1 : 1);
	double x0=p1._x;
	double y0=p1._y;
	double proizv=Proizv(x0, up);
	//double  vr5=PROIZVODNAYA(_r, p1._x, _centr._x, up);
	//double vr1=1/(2*sqrt(4-(x0-2)*(x0-2)))*(-(x0-2+x0-2));
	p2._y = y0 + proizv*(p2._x-x0);
	ret._begin=p1;
	ret._end=p2;
	ret.CalcLong();
	return ret;
}
