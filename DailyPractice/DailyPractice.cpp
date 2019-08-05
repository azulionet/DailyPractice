#include "pch.h"




using namespace std;


class Test1
{
public:
	Test1(const char* name) : myName(name)
	{
	}

	~Test1()
	{
		cout << myName << endl;
	}

	const char* myName;
};

#include <memory>

int main()
{
	std::shared_ptr<Test1> a(new Test1("hi"));

	{
		std::shared_ptr<Test1> b(new Test1("hello"));

		a = b;
	}
	
	cout << "aaaa" << endl;
	cout << a->myName << endl;
	cout << "aaaa" << endl;


	getchar();
	return 0;
}

