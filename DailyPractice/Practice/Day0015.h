#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

#include <functional>

using namespace placeholders;

class FF
{
	
public:

	int Add(int a, int b)
	{
		cout << "a : " << a << endl;
		cout << "b : " << b << endl;
		cout << "n : " << n << endl;

		return a + b + n;
	}

	int Check(int a) const
	{
		return a * a*a;
	}

	int operator()(int a) const
	{
		return a + n;
	}

	int n = 10;
};



template<size_t N>
class Fibo
{
	static_assert(N >= 2);

public:
	const static int N = (Fibo<N - 2>::N) + (Fibo<N - 1>::N);
};

template<>
class Fibo<1>
{
public:
	const static int N = 1;
};

template<>
class Fibo<0>
{
public:
	const static int N = 0;
};



bool is_prime(int N) {
	if (N == 2) return true;
	if (N == 3) return true;

	for (int i = 2; i <= N / 2; i++) {
		if (N % i == 0) return false;
	}

	return true;
}

template<size_t N>
struct Prime
{
	static_assert(N >= 2);
	const static bool bResult = true;
};

template<>
struct Prime<2>
{
	const static bool bResult = true;
};
template<>
struct Prime<3>
{
	const static bool bResult = true;
};

template<int N, int D>
struct CheckDiv
{
	static const bool bResult = (N%D == 0) || CheckDiv<N, D + 1>::bResult;
};



void TestFunctional15()
{
	cout << Fibo<1>::N << endl;
	
	// FF e;

	// std::function<int(int, int)> pp = std::bind(&FF::Add, ref(e), 10, _1);

	// auto p = mem_fn(&FF::Add);	
	// cout << p(e, 1, 2) << endl;

// 	std::function<int(int, int)> a = 


}





END_PRACTICE
