#pragma once
#include "curvspline.h"
class EXPORT_OR_IMPPORT CurvSplineCircl :
	public CurvSpline
{
private :
	double _r;
	CurvDPoint _centr;
public:
	double Proizv(double x, bool up);
	CurvSplineCircl(double r);
	CurvSplineCircl(double r, double x, double y);
	virtual ~CurvSplineCircl(void);
	virtual double Radius() {  return _r; };
	virtual const char * Obzivis() { return "CurvSplineCircl"; };
	virtual CurvDPoint GetPoint(double t);
	virtual CurvVector GetVector(double t);
};

