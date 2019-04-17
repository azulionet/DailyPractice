#include "pch.h"

#include "Practice/Day0009.h"


USING_PRACTICE

#include <cassert>

using namespace std;

class Printable
{
public:
	int GetValue() const
	{
		return 10;
	}
};


class Printable2
{
public:
	int GetValue() const
	{
		return 2;
	}
};

class Printable3
{
public:
	int GetValue() const
	{
		return 3;
	}
};

using namespace std;

template<typename T>
ostream& operator<<(ostream& o, const T& p)
{
	o << p.GetValue();
	return o;
}

// 오퍼레이션 오버로딩 ostream, Printable 함수 제작 ㄱ

int main()
{
	using namespace std;

	cout << Printable{} << endl;
	cout << Printable2{} << endl;
	cout << Printable3{} << endl;

	getchar();
}
