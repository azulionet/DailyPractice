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


static constexpr auto table = gen_table();



int main()
{
	using clock = std::chrono::high_resolution_clock;
	using millisec = std::chrono::milliseconds;

// 	for (auto const& row : table)
// 	{
// 		for (auto const& col : row)
// 		{
// 			std::cout << std::setw(2) << col << " ";
// 			std::cout << '\n';
// 		}
// 	}

	const int nCount = 1000000;

	float fVal = 0;
	for (int i = 0; i < 100; ++i)
	{
		fVal += MySqrt(i);
	}


	auto val = clock::now();

	fVal = 0;
	for (int i = 0; i < nCount; ++i)
	{
		fVal += MySqrt(i);
	}

	auto milliSec = std::chrono::duration_cast<millisec>(clock::now() - val);
	cout << "mysqrt : 정수" << milliSec.count() << endl;
	cout << fVal << endl;


	val = clock::now();

	fVal = 0;
	for (int i = 0; i < nCount; ++i)
	{
		fVal += std::sqrt(i);
	}

	milliSec = std::chrono::duration_cast<millisec>(clock::now() - val);
	cout << "sqrt : 정수" <<  milliSec.count() << endl;
	cout << fVal << endl;





	val = clock::now();

	fVal = 0;
	for (int i = 0; i < nCount; ++i)
	{
		fVal += MySqrt(i + 0.1f);
	}

	milliSec = std::chrono::duration_cast<millisec>(clock::now() - val);
	cout << "mysqrt : 실수" << milliSec.count() << endl;
	cout << fVal << endl;


	val = clock::now();

	fVal = 0;
	for (int i = 0; i < nCount; ++i)
	{
		fVal += std::sqrt(i + 0.1f);
	}

	milliSec = std::chrono::duration_cast<millisec>(clock::now() - val);
	cout << "sqrt : 실수" << milliSec.count() << endl;
	cout << fVal << endl;




	getchar();
	return 0;
}
