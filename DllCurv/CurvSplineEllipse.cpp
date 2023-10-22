#include "stdafx.h"
#include "CurvSplineEllipse.h"
#include <cmath>
using namespace std;



CurvSplineEllipse::CurvSplineEllipse(double a, double b)
{
	_a=a;
	_b=b;
	_centr._x=_centr._y=_centr._z=0;
}
CurvSplineEllipse::CurvSplineEllipse(double a, double b, double x, double y)
{
	_a=a;
	_b=b;
	_centr._x=x;
	_centr._y=y;
	_centr._z=0;
}


CurvSplineEllipse::~CurvSplineEllipse(void)
{
}

	
double CurvSplineEllipse::Proizv(double x, bool up)
{
	double ret=-x*sqrt(
		_b*_b*(_a*_a-x*x)/(_a*_a)
		)
	/
	(_a*_a-x*x);
	if(!up) ret=-ret;
	return ret;
}

	
CurvDPoint CurvSplineEllipse::GetPoint(double t) {
	//направление
	double sin1=std::sin(t), cos1=cos(t), x, y;
	double gradus=t*180/3.14;
	bool up=(sin1 >= 0);
	bool right=(cos1 >= 0);
	//координаты
	x = sqrt ( pow(_b, 2) / (pow(std::sin(t), 2) + pow(_a, 2) )  );
	y = sqrt(  ((_b*_b) / (_a*_a)) * (_a*_a - x*x)   );
	if(!up) y=-y;
	if(!right) x=-x;
	//возвращаем
	CurvDPoint ret;
	ret._x=x+_centr._x;
	ret._y=y+_centr._y;
	ret._z=0+_centr._z;
	return ret;
}
CurvVector CurvSplineEllipse::GetVector(double t) {
	CurvVector ret;
	CurvDPoint p1=GetPoint(t), p2;
	bool up=(std::sin(t) >= 0);
	p2._z=0;
	p2._x=p1._x+(up ? -1 : 1);
	double x0=p1._x;
	double y0=p1._y;
	double proizv=Proizv(x0, up);
	p2._y = y0 + proizv*(p2._x-x0);
	ret._begin=p1;
	ret._end=p2;
	ret.CalcLong();
	return ret;
}
