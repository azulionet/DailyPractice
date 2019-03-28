// DailyPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

#include <vld.h>

// #include "Practice/Day0001.h"
// #include "Practice/Day0002.h"
#include "Practice/Day0006.h"

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
			m > d | m < q ? q : q = m;
	return q ? q : -1;
}


int main()
{
	cout << differentValues({ 1,2,3 }, 0) << endl;

	getchar();
	return 0;
}
