#include "pch.h"

using namespace std;



union S
{
	S() : c{} { cout << "union s" << endl; }
	char c;
	int a;
	char ar[4];
};

void TestS()
{
	S a;

	cout << (int)a.c << endl;
	cout << (int)a.a << endl;

	for (auto val : a.ar)
	{
		cout << (int)val << endl;
	}
}

struct S2
{
	struct
	{
		int a;
		int b;
	};

	class {
	public:
		int c;
		int d;
	};


	void Print()
	{
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
		cout << d << endl;
	}
};

void TestS2()
{
	S2 aaaa;

	aaaa.Print();
}



int main()
{
	TestS2();
	getchar();
	return 0;
}

