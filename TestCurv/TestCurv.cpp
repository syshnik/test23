// TestCurv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>    
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <omp.h>

using namespace std;

//сравнение радиусов
bool myfunction (CurvSpline * i, CurvSpline *j) {
	return (i->Radius() < j->Radius());
}
/*
void Test5() {
	CurvSplineCircl c1(2, 2, 4);
	CurvVector ret1=c1.GetVector(1);
	CurvVector ret11=c1.GetVector(4);
	CurvSplineEllipse c2(3, 4, 1, 2);
	c2.GetPoint(1);
	CurvVector ret2=c2.GetVector(1);
	CurvSplineEllipse c3(3, 4, 1, 2);
	c3.GetPoint(4);
	CurvVector ret3=c3.GetVector(4);
	int vr444=0;
}
*/
const int g_nNumberOfThreads = 4;
#define SIKOKO 20
int _tmain(int argc, _TCHAR* argv[])
{
//	Test5();
	std::vector<CurvSpline *> v1, v2;
	//заполнение случайными элементами
	for(int n1=0; n1<SIKOKO; n1++) {
		CurvSpline * p1=NULL;
		if(rand()%3 == 0) p1 = new CurvSplineCircl(1+rand()%100);
		else if(rand()%2 == 0) p1 = new CurvSplineEllipse(1+rand()%100, 1+rand()%100);
		else p1 = new CurvSplineSpiral(1+rand()%100);
		v1.push_back(p1);
	}
	//Выведите координаты точек и производные всех кривых в контейнере при t=PI/4.
	for(int n1=0; n1<v1.size(); n1++) {
		CurvSpline * p1=v1[n1];
		CurvVector v1=p1->GetVector(3.14159265358979323846 / 4);
		cout << p1->Obzivis() << "   x=" << v1._begin._x << ", y=" << v1._begin._y << ", z=" <<  v1._begin._z << ", f'(x)=" << v1._end._y << "\n"; 
	}
	//заполнение кругами
	for(int n1=0; n1<v1.size(); n1++) {
		CurvSpline * p1=v1[n1];
		char const * name = p1->Obzivis();
		if(!strcmp(name, "CurvSplineCircl"))
			v2.push_back(p1);
	}
	//
	for(int n1=0; n1<v2.size(); n1++) cout << "r=" << v2[n1]->Radius() << "\n";

	//сортировка
	std::sort (v2.begin(), v2.end(), myfunction); 
	//
	cout << "Sort-----------------\n";
	for(int n1=0; n1<v2.size(); n1++) cout << "r=" << v2[n1]->Radius() << "\n";
	//вычисление в одном потоке
	{
		double sum=0;
		for(int i = 0; i < v2.size(); i++) {
			CurvSpline * p1=v2[i];
			sum+=p1->Radius();
		}
		cout << "Summa Radius 1  =  " << sum << "\n";
	}
	//вычисление в нескольких потоках
	{
		double sum=0;
		omp_set_num_threads(g_nNumberOfThreads);
		#pragma omp parallel for shared(sum)
		for(int i = 0; i < v2.size(); i++) {
			CurvSpline * p1=v2[i];
			double r=p1->Radius();
			#pragma omp critical
			sum+=r;
		}
		cout << "Summa Radius 2  =  " << sum << "\n";
	}
	//освобождение памяти
	for(int n1=0; n1<v1.size(); n1++) {
		CurvSpline * p1=v1[n1];
		char const * name = p1->Obzivis();
		if(!strcmp(name, "CurvSplineCircl")) delete ((CurvSplineCircl*)(p1));
		else if(!strcmp(name, "CurvSplineEllipse")) delete ((CurvSplineEllipse*)(p1));
		else if(!strcmp(name, "CurvSplineSpiral")) delete ((CurvSplineSpiral*)(p1));
		else {
			abort();
		}
	}
	int c55;
	cout << "input n\n";
	cin >> c55;
	return 0;
}

