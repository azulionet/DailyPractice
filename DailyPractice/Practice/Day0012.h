#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

#include <iostream>

using namespace std;

using int32 = signed int;
using int8 = signed char;

using uint32 = unsigned int;
using uint8 = unsigned char;


enum class eStackException
{
	EmptyBuffer = 0,
};

template<typename T, uint32 N>
class MyStack
{
	static_assert(N <= 32);

public:

	void Push(const T& val);
	void Pop();
	T Peek();

private:

	T		m_Buffer[N];
	int32	m_nTop = -1;
};

template<typename T, uint32 N>
void MyStack<T, N>::Push(const T& val)
{
	if (m_nTop == N - 1) { return; }

	++m_nTop;
	m_Buffer[m_nTop] = val;
}

template<typename T, uint32 N>
void MyStack<T, N>::Pop()
{
	if (m_nTop < 0) { throw eStackException::EmptyBuffer; }
	--m_nTop;
}

template<typename T, uint32 N>
T MyStack<T, N>::Peek()
{
	if (m_nTop < 0) { throw eStackException::EmptyBuffer; }

	return m_Buffer[m_nTop];
}



template<uint32 N>
class MyStack<bool, N>
{
	static_assert(N <= 32);

public:

	void Push(const bool& val)
	{
		if (m_nTop == N - 1) { return; }

		++m_nTop;

		if (val == true)
		{
			m_Buffer |= (1 << m_nTop);
		}
		else
		{
			m_Buffer &= ~(1 << m_nTop);
		}
	}

	void Pop()
	{
		if (m_nTop < 0) { throw eStackException::EmptyBuffer; }
		
		--m_nTop;
	}

	bool Peek()
	{
		if (m_nTop < 0) { throw eStackException::EmptyBuffer; }

		return m_Buffer & (1 << m_nTop);
	}

private:

	int		m_Buffer = 0;
	int32	m_nTop = -1;
};


END_PRACTICE
