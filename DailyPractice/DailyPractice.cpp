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

#include <functional>
#include <memory>



class c
{
public:
	void Add(int a)
	{
		cout << a << endl;
	}
};

#include <type_traits>





enum class Check
{
	a,b,c
};

template<typename T>
class A
{
	static_assert(std::is_enum<T>::value);

};

#include <vld.h>
#include "Day0030.h"

int main(int n, const char* ar[])
{
	Tree t;


	t.Add_Plain(10);

	// left
	t.Add_Plain(5);

	t.Add_Plain(3);
	t.Add_Plain(8);

	t.Add_Plain(4);
	t.Add_Plain(2);
	t.Add_Plain(7);
	t.Add_Plain(9);
	
	
	// right
	t.Add_Plain(15);

	t.Add_Plain(13);
	t.Add_Plain(18);

	t.Add_Plain(14);
	t.Add_Plain(12);
	t.Add_Plain(16);
	t.Add_Plain(19);




	t.PrintPreOrder(t.h);


	Node* p = t.FindLeastCommonAncestor(7, 19);

	cout << p->v << endl;
	


	getchar();
	getchar();


	return 0;
}
