﻿#include "pch.h"

using namespace std;


template<typename T, typename U, size_t n = 20, size_t ee = 30>
class A
{
public:

	A()
	{
		cout << "Normal des" << endl;
	}

	~A()
	{
		cout << "Normal dtor" << endl;
	}

	void Init()
	{
		cout  << "a : " << a << endl;
		cout << "b : " << b << endl;
		cout << n << endl;
	}

	T a;
	U b;
};

template<>
A<int, int>::A()
{
	cout << "int int" << endl;
}

A<int, int>::~A()
{
	cout << "int int dtor" << endl;
}



template<>
A<int, double>::A()
{
	cout << "int double" << endl;
}

void MyTestabcd()
{
	A<int, int> a;
	A<int, int, 8> e;
	A<int, double> d;
	A<int, float, 1> ffg;

	a.Init();
	d.Init();
	e.Init();
}

int main()
{


	MyTestabcd();

	getchar();
	return 0;
}

