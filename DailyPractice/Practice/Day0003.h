#pragma once

#include "DailyPractice/Define.h"
#include "DailyPractice/Component/PracticePool.h"

BEGIN_PRACTICE

// https ://app.codesignal.com/arcade/intro/level-2/bq2XnSr5kbHqpHGJC
size_t makeArrayConsecutive2(std::vector<int> statues)
{
	auto[min, max] = std::minmax_element(std::begin(statues), std::end(statues));
	
	return std::abs(*max-*min) - statues.size() + 1;
}

// cpp레퍼런스 예제
static constexpr int nRows = 3, nCols = 2;
static constexpr double p_calc(double a, double b) { return a + b; }

static constexpr double t[nRows] = { 0, 10, 20 };
static constexpr double r[nRows][nCols] = { {0,1}, {3,4}, {6,7} };

template<std::size_t Row, std::size_t... Cols>
static constexpr std::array<double, nCols> gen_row(std::index_sequence<Cols...>)
{
	return { p_calc(t[Row], r[Row][Cols])... };
}

template<std::size_t... Rows>
static constexpr std::array<std::array<double, nCols>, nRows>
gen_table(std::index_sequence<Rows...>)
{
	return { gen_row<Rows>(std::make_index_sequence<nCols>())... };
}

static constexpr std::array<std::array<double, nCols>, nRows>
gen_table() { return gen_table(std::make_index_sequence<nRows>()); }


// 피보나치 수열 constexpr
constexpr size_t fibo(size_t n)
{
	return (n <= 1) ? n : fibo(n - 2) + fibo(n - 1);
}

enum class eFibo
{
	_10 = fibo(10),
	_20 = fibo(20),
};

template<size_t N>
struct Fibo_t
{
	static const long long val = Fibo_t<N - 2>::val + Fibo_t<N - 1>::val;
};

template<>
struct Fibo_t<1>
{
	static const long long val = 1;
};

template<>
struct Fibo_t<0>
{
	static const long long val = 0;
};


float MySqrt(float a_fVal)
{
	float x = 1.0;
	float input = a_fVal;

	for (int i = 0; i < 20; i++) // sqrt 구현
	{
		x = (x + (input / x)) / 2;
	}

	return x;
}

// constexpr int CONST_EXPR_makeArrayConsecutive2(const int[] statues, const int b)
// {
// 	int nMin = INT_MAX;
// 	int nMax = INT_MIN;
// 	int nSize = b;
// 
// 	for (int i = 0; i < nSize; ++i)
// 	{
// 		if (statues[i] > nMax)
// 		{
// 			nMax = statues[i];
// 		}
// 
// 		if (statues[i] < nMin)
// 		{
// 			nMin = statues[i];
// 		}
// 	}
// 
// 	return nMax - nMin - nSize + 1;
// }


END_PRACTICE
