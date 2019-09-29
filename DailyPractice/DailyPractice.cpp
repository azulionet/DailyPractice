#include "pch.h"

#include <vld.h>

using namespace std;



#include <limits>



template<typename T>
[[nodiscard]] T Input()
{
	T val;

	while (true)
	{
		cin >> val;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');

			cout << typeid(T).name() << " : 입력 에러" << endl;
		}
		else { break; }
	}

	cin.ignore(INT_MAX, '\n');
	return val;
}



#include "Day0029.h"

int main(int n, const char* ar[])
{
	Day0029 eee;


	getchar();
	getchar();

	return 0;
}

