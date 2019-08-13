#include "pch.h"

using namespace std;

#include "Day0022.h"


struct Test_Struct_NoOption;
struct Test_Struct_NoExcept;
struct Test_Struct_Explicit;
struct Test_Struct_NoExcept_Explicit;
class Test_Class_NoOption;
class Test_Class_NoExcept;
class Test_Class_Explicit;
class Test_Class_NoExcept_Explicit;





void MyTestabcd()
{
	using TestType = Test_Struct_NoExcept;
	cout << typeid(TestType).name() << endl;

	std::vector<TestType> a;

	// 주석 / 안주석
	// a.reserve(10);

	cout << "emplace back ------------------" << endl;
	a.emplace_back(6, 6);

	cout << "emplace back temp------------------" << endl;
	a.emplace_back(TestType{ 7, 6 });

	cout << "push back temp------------------" << endl;
	a.push_back(TestType{ 7, 6 });


	cout << "ranged - for ------------------" << endl;
	for (const auto& val : a)
	{
		std::cout << val.GetA() << std::endl;
	}

}

int main()
{


	MyTestabcd();

	getchar();
	return 0;
}

