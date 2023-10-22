#pragma once
#include "curvspline.h"
class EXPORT_OR_IMPPORT CurvSplineSpiral :
	public CurvSpline
{
	double _r;//, _shag;
	CurvDPoint _centr;
public:
	CurvSplineSpiral(double r);
	virtual ~CurvSplineSpiral(void);
	virtual double Radius() {  return _r; };
	virtual const char * Obzivis() { return "CurvSplineSpiral"; };
	virtual CurvDPoint GetPoint(double t);
	virtual CurvVector GetVector(double t);
};

