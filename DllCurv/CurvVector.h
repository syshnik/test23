#pragma once
class EXPORT_OR_IMPPORT CurvVector
{
public:
	CurvDPoint _begin , _end;
	double _l;
	CurvVector(void);
	~CurvVector(void);
	void CalcLong();
};

