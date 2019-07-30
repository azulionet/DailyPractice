#pragma once


template<typename T>
class AA
{
	using fp = T;

public:

	std::function<T> tt;

	void Set(T ee)
	{
		tt = ee;
		cout << "setted" << endl;
	}

	static void Call(std::function<T> f, int print)
	{
		f(print);
		cout << "called" << endl;
	}

};

int __cdecl AAA(int b)
{
	cout << "AAA" << endl;
	return b;
}

int __stdcall BBB(int b)
{
	cout << "BBB" << endl;
	return b * b;
}

class EE
{
public:

	int EE_GetNum(int nn) const
	{
		cout << m_nNum << " efioejf" << endl;

		return m_nNum * nn;
	}

	int m_nNum = 50;


	int GetNum_NoMember(int t) const
	{
		return m_nNum * t;
	}
};



template<typename T, typename U>
T Add(T a, U b) // T혹은 U로 리턴타입이 고정됨.
{
	static int nCount = 0;

	++nCount;

	cout << "eifjeiofjf" << nCount << endl;

	return a + b;
}

// 1. 세번째 템플릿 파라미터 ㄱ
// 2. 컴파일러가 반환형을 찾게함.
// 3. 두 파라미터 공통 형식으로 선언

// auto로 리턴! 반환형이 여러개일 경우, 각타입의 반환타입은 일정해야만함



/* 스태틱 동작, 리턴타입 추론
template<typename T, typename U>
auto Add(T a, U b) ->decltype(a+b)
{
	static int nCount = 0;

	++nCount;

	cout << "eifjeiofjf" << nCount << endl;

	return a + b;
}
*/

/*
	AA<int(int)> ee;

	ee.Set([](int a) {return 10; });
	AA<int(int)>::Call([](int a) {return 10; },6);

	AA<int(int)>::Call(AAA, 2);
	AA<int(int)>::Call(BBB, 4);

	EE aaaa;


	using std::placeholders::_1;
	std::function<int(int)> ff = std::bind(&EE::EE_GetNum, std::ref(aaaa), _1);

	auto p = bind(&EE::EE_GetNum, std::ref(aaaa), _1);
	cout << "p(50) : " << p(50) << endl;


	std::function<int_int> eeff = [](int a) {return a * a; };

	cout << "eeff" << endl;
	cout << eeff(10) << endl;


	auto ii = [](int a) {return a * a; };
	// std::function<int(void)> e5 = std::bind(ii, 10, _1);

	auto fff5 = std::bind(ii, 10);
	fff5();



	AA<int(int)>::Call(ff, 100);

	// 클래스

	cout << "class bind" << endl;
	p(10);
	cout << aaaa.m_nNum << endl;


	cout << endl << endl << endl;
	cout << "tempalte function" << endl;
	cout << Add(10, 20.03) << endl;
	cout << Add(10, 20.03) << endl;
	cout << Add(10, 20.03) << endl;

	cout << Add(1, 1) << endl;
	cout << Add(1.3f, 1.5f) << endl;
	*/




template<typename T>
bool Max(const T& a, const T& b) //Type T 는 복사 (old cpp) 혹은 이동(cpp 17) 가능해야함
{
	return b < a ? a : b;
}


template<typename T1, typename T2>
auto Max22(T1 a, T2 b) -> decltype(a + b)
{
	static int nCount = 0;

	cout << typeid(decltype(a + b)).name() << endl;

	cout << "===" << __FUNCTION__ << nCount++ << endl;

	return b < a ? a : b;
}

using namespace placeholders;


using int_int = int(int);


// auto 형 소실. int i = 0; const int& a = i; auto ii = a; // ii는 int! 
