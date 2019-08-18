#include "pch.h"
#include "Day0025.h"

class A
{
	int _1()
	{
		return 1;
	}

	float _2()
	{
		return 2.5f;
	}

public:

	int a = 1;
	int b = 2;
	int c = 3;
};


void Test0025()
{
	using namespace std;
	using namespace placeholders;


	std::tuple<int, int, int> aa;
	
	auto[x,y,z] = A();

	cout << x << endl;

	cout << y << endl;

	cout << z << endl;



}

