#pragma once
class EXPORT_OR_IMPPORT CurvSpline
{
public:
	CurvSpline(void);
	virtual ~CurvSpline(void);
	virtual double Radius() {  return 0; };
	virtual const char * Obzivis() { return "CurvSpline"; };
	virtual CurvDPoint GetPoint(double t) { return CurvDPoint(); };
	virtual CurvVector GetVector(double t) { return CurvVector(); };
};

