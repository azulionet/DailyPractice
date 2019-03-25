// DailyPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"


// #include "Practice/Day0001.h"
// #include "Practice/Day0002.h"
#include "Practice/Day0003.h"

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



void main()
{
	
	constexpr auto val = std::minmax<int>({ 1,2,6,4,7,9 });

	A<val.first>;


	cout << makeArrayConsecutive2({ 6,2,3,8 }) << endl;
	


	getchar();
}
