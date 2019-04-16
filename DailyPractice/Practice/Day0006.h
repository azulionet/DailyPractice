#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE


// ����� �̿��� ����
template<typename T>
void Swap(T& a, T& b)
{
	a += b;
	b = a - b;
	a -= b;
}

template<typename T>
inline void SwapInline(T& a, T& b)
{
	a += b;
	b = a - b;
	a -= b;
}

#define DSwap(a, b) \
{ \
	(a) += (b); \
	(b) = (a)-(b); \
	(a) -= (b); \
}


#define DVSwap(a, b) \
{ \
	int t = a; \
	a = b; \
	b = t; \
}

// ����� �̿��� ����
template<typename T>
void SwapNormal(T& a, T& b)
{
	T& t = a;
	a = b;
	b = t;
}

template<typename T>
inline void SwapNormalInline(T& a, T& b)
{
	T& t = a;
	a = b;
	b = t;
}

void Test222()
{
	int a = 10, b = 5;

	auto tStamp = timeGetTime();

	const int nCount = 10000;

	for (int i = 0; i < nCount; ++i)
	{
		for (int j = 0; j < nCount; ++j)
		{
			DSwap(a, b);
		}
	}

	auto now = timeGetTime() - tStamp;

	cout << "��ũ��" << now << endl;


	a = 10, b = 5;

	tStamp = timeGetTime();

	for (int i = 0; i < nCount; ++i)
	{
		for (int j = 0; j < nCount; ++j)
		{
			Swap(a, b);
		}
	}

	now = timeGetTime() - tStamp;

	cout << "���ø� ����" << now << endl;


	a = 10, b = 5;

	tStamp = timeGetTime();

	for (int i = 0; i < nCount; ++i)
	{
		for (int j = 0; j < nCount; ++j)
		{
			SwapInline(a, b);
		}
	}

	now = timeGetTime() - tStamp;

	cout << "���ø� �ζ��� ����" << now << endl;




	a = 10, b = 5;

	tStamp = timeGetTime();

	for (int i = 0; i < nCount; ++i)
	{
		for (int j = 0; j < nCount; ++j)
		{
			DVSwap(a, b);
		}
	}

	now = timeGetTime() - tStamp;

	cout << "��ũ�� - ���뽺��" << now << endl;



	a = 10, b = 5;

	tStamp = timeGetTime();

	for (int i = 0; i < nCount; ++i)
	{
		for (int j = 0; j < nCount; ++j)
		{
			SwapNormal(a, b);
		}
	}

	now = timeGetTime() - tStamp;

	cout << "���ø� - ���뽺��" << now << endl;



	a = 10, b = 5;

	tStamp = timeGetTime();

	for (int i = 0; i < nCount; ++i)
	{
		for (int j = 0; j < nCount; ++j)
		{
			SwapNormalInline(a, b);
		}
	}

	now = timeGetTime() - tStamp;

	cout << "���ø� - ���뽺�� �ζ���" << now << endl;

}




class Adder
{
public:



};





END_PRACTICE
