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




template<size_t N>
struct DropTheBit
{
	enum
	{
		Val = (DropTheBit<N / 10>::Val*2) + DropTheBit<N % 2>::Val
	};
};

template<>
struct DropTheBit<0>
{
	enum { Val = 0 };
};

template<>
struct DropTheBit<1>
{
	enum { Val = 1 };
};




void Recursive() {} // 종료를 위해 필요

template<typename T, typename... Types> void Recursive(T value, Types... args)
{
	static int n = 0;
	n++;
	cout << n << endl;

	cout << typeid(T).name() << " : " << value << endl;

	Recursive(args...);
}


void TestFunctional15()
{
	// Recursive(1, 2.5f, 3.2, 4, 5, 6);
	cout << DropTheBit<1101>::Val << endl;
	cout << DropTheBit<1111>::Val << endl;
	cout << DropTheBit<1>::Val << endl;
	cout << DropTheBit<111>::Val << endl;
}


struct E
{
	E(int _b, int _c) : b(_b), c(_c) { }
	E(E&& a) noexcept : b{ a.b }, c{ a.c }  { cout << "E : && " << endl; }
	E(const E& a) : b{ a.b }, c{ a.c }  { cout << "c E : & " << endl; }

	int b = 0;
	int c = 1;
};


void eeeee()
{
	std::vector<E> a;

	a.emplace_back(1, 1);
	a.emplace_back(2, 2);
	a.emplace_back(3, 3);



	

}

END_PRACTICE
