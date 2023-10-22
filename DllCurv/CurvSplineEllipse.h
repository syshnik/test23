#pragma once
#include "curvspline.h"
class EXPORT_OR_IMPPORT CurvSplineEllipse :
	public CurvSpline
{
	double _a, _b;
	CurvDPoint _centr;
public:
	double Proizv(double x, bool up);
	CurvSplineEllipse(double a, double b);
	CurvSplineEllipse(double a, double b, double x, double y);
	virtual ~CurvSplineEllipse(void);
	virtual double Radius() {  return 0; };
	virtual const char * Obzivis() { return "CurvSplineEllipse"; };
	virtual CurvDPoint GetPoint(double t);
	virtual CurvVector GetVector(double t);
};

