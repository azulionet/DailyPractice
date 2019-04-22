#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

#include <iostream>
#include <cassert>

class MyString
{

public:

	MyString() = default;
	MyString(const char* p)
	{
		if (p == nullptr) { assert("arg error"); return; }

		size_t nLen = strlen(p);
		m_pBuffer = new char[nLen + 1];
		strcpy_s(m_pBuffer, nLen + 1, p);
		m_pBuffer[nLen] = 0;
		m_nSize = nLen;
	}

	// 복사 생성자
	MyString(const MyString& t) : MyString(t.m_pBuffer) { };

	// 이동 생성자
	MyString(MyString&& tt) : m_pBuffer(tt.m_pBuffer), m_nSize(tt.m_nSize)
	{
		tt.m_pBuffer = nullptr;
		tt.m_nSize = 0;
	}

	~MyString()
	{
		SAFE_DELETE_ARR(m_pBuffer);
	}

public: // operator -------------------------------------------------------------------------------------------
	
	void operator=(const MyString& t)
	{
		SAFE_DELETE_ARR(m_pBuffer);

		int nLen = t.m_nSize;
		m_pBuffer = new char[nLen + 1];
		strcpy_s(m_pBuffer, nLen + 1, t.m_pBuffer);
		m_pBuffer[nLen] = 0;
		m_nSize = nLen;
	}

	void operator=(MyString&& tt)
	{
		SAFE_DELETE_ARR(m_pBuffer);

		m_pBuffer	= tt.m_pBuffer;
		m_nSize		= tt.m_nSize;

		tt.m_pBuffer= nullptr;
		tt.m_nSize	= 0;
	}

	MyString operator+(const char* s)
	{
		if (s == nullptr) { assert(false && "arg error"); return *this; }

		size_t nLen = m_nSize + strlen(s);
		char* p = new char[nLen + 1];
		char* pTemp = p;

		strcpy_s(pTemp, nLen + 1, m_pBuffer);
		pTemp += m_nSize;

		strcpy_s(pTemp, nLen + 1 - m_nSize, s);
		pTemp = nullptr;

		MyString MyTempString;
		MyTempString.ReplaceBuffer(p);

		return MyTempString;
	}

	MyString operator+(const MyString& t)
	{
		this->operator+(t.GetBuffer());
	}

	MyString& operator+=(const char* s)
	{
		if (s == nullptr) { assert(false && "arg error"); return *this; }

		size_t nLen = m_nSize + strlen(s);
		char* p = new char[nLen + 1];
		char* pTemp = p;

		strcpy_s(pTemp, nLen + 1, m_pBuffer);
		pTemp += m_nSize;

		strcpy_s(pTemp, nLen + 1 - m_nSize, s);
		pTemp = nullptr;

		ReplaceBuffer(p);

		return *this;
	}

	MyString& operator+=(const MyString& t)
	{
		return this->operator+=(t.GetBuffer());
	}

public: // 인터페이스 -------------------------------------------------------------------------------------------

	char* GetBuffer() const { return m_pBuffer; }
	size_t Size() const		{ return m_nSize; }

private:

	void ReplaceBuffer(char* a_pBuffer)
	{
		if (m_pBuffer != nullptr) { delete m_pBuffer; }

		m_pBuffer = a_pBuffer;
		m_nSize = a_pBuffer == nullptr ? 0 : strlen(a_pBuffer);
	}

private:
	char* m_pBuffer = nullptr;
	size_t m_nSize = 0;
};


END_PRACTICE
