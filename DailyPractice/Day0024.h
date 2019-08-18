#pragma once


template<typename T, typename U, size_t n = 20, size_t ee = 30>
class A
{
public:

	A()
	{
		cout << "Normal des" << endl;
	}

	void Init()
	{
		cout << "a : " << a << endl;
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

class Day0024
{
public:
	Day0024();
	~Day0024();
};
