#include "pch.h"

using namespace std;

#include <memory>
#include "Day0021.h"

class Base
{
protected:
	int i;
public:
	Base(int a) { i = a; }
	virtual void display() const
	{
		cout << "I am Base class object, i = " << i << endl;
	}
};

class Derived : public Base
{
	int j;
public:
	Derived(int a, int b) : Base(a) { j = b; }
	virtual void display() const
	{
		cout << "I am Derived class object, i = "
			<< i << ", j = " << j << endl;
	}
};

void somefunc(const Base& obj)
{
	obj.display();
}

void somefunc2(Base obj)
{
	obj.display();
}


int main()
{
	Base b(33);
	Derived d(45, 54);
	somefunc(b);
	somefunc(d);
	somefunc2(b);
	somefunc2(d);

	getchar();
	return 0;
}

