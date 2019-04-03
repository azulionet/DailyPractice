// DailyPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

#include <vld.h>
#include "Practice/Day0007.h"

using namespace std;

USING_PRACTICE

template<int N>
class A
{
public:
	constexpr A()
	{
		std::cout << N << "\n";
	}
};

int differentValues(std::vector<int> a, int d)
{
	int q = 0;
	for (int n : a)
		for (int m : a)
			m -= n,
			(m > d | m < q) ? q : q = m;
	return q ? q : -1;
}

int soSsSos(int _) { return ++_*--_*--_*9 / 0xc; }

int s(int _) { return ++_ + (++_ << 1); }

int main()
{
// 	std::vector<int> a = { 1,6,34, 8,3,2, 29, 3, 6, 1 };
// 	std::vector<int> b;
// 
// 	Copy(a, b);
// 
// 	for (auto& val : b)
// 	{
// 		std::cout << val << '\t';
// 	}
// 
// 	std::cout << endl;
// 	std::cout << endl;
// 
// 	UniqueCopy(a, b);
// 
// 	for (auto& val : b)
// 	{
// 		std::cout << val << endl;
// 	}

// 	std::list<int> a{ 1,2,3,4,5,6,11, 12, 13, 1,2,3 };
// 
// 	for (auto itor : Practice::FindAll(a, 1))
// 	{
// 		cout << *itor << endl;
// 	}
// 
// 	std::vector<int> b{ 1,2,3,4,5,6,11, 12, 13, 1,2,3 };
// 
// 	for (auto vcItor : Practice::FindAll(b, 1) )
// 	{
// 		cout << *vcItor << endl;
// 	}



	PrintTwoWord("Hello", "World!!");

	std::vector<std::string> vc{
		"ab",
		"bc",
		"cd",
		"ab",
		"cc",
		"de"
	};

	std::set<std::string> set
	{
		vc.begin(), vc.end()
	};

	for (auto val : set)
	{
		cout << val << endl;
	}


	FileIO2();


	B();
	
	getchar();

	return 0;
}
