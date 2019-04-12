#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

using namespace std;

class TempArr;
TempArr operator+(const TempArr& A, const TempArr& B);

class TempArr
{
public:

	TempArr() = default;
	TempArr(const char* p)
	{
		size_t nLen = strlen(p);
		m_pBuffer = new char[nLen + 1];
		strcpy_s(m_pBuffer, nLen + 1, p);
		m_pBuffer[nLen] = 0;
		m_nSize = nLen;

		cout << "������ : " << nLen << " ����Ʈ ����" << endl;
	}

	// ���� ������
	TempArr(const TempArr& t) : TempArr(t.m_pBuffer) { };

	// �̵� ������
	TempArr(TempArr&& tt) : m_pBuffer(tt.m_pBuffer), m_nSize(tt.m_nSize)
	{
		tt.m_pBuffer = nullptr;
		tt.m_nSize = 0;

		cout << "�̵�������" << endl;
	}

	~TempArr()
	{
		// SAFE_DELETE_ARR(m_pBuffer);

		if (m_pBuffer != nullptr)
		{
			cout << "�޸𸮸� ������! �޸� ũ�� : " << m_nSize << endl;			
			delete[] m_pBuffer;
			m_pBuffer = nullptr;
		}
	}

public: // operator -------------------------------------------------------------------------------------------
	void operator=(const TempArr& t) = delete;
	// void operator=(const TempArr& tt); // ������ ���Ǹ� �����ʾƵ� ����� ��, ��ũ������ ��

	char* begin() const { return m_pBuffer; }

	char* end() const
	{
		if (m_pBuffer == nullptr) { return nullptr; }
		return m_pBuffer + m_nSize;
	}

public: // �������̽� -------------------------------------------------------------------------------------------

	char* GetBuffer() const			{ return m_pBuffer; }
	size_t Size() const				{ return m_nSize; }
	void ReplaceBuffer(char* a_pBuffer)
	{
		if (m_pBuffer != nullptr) { delete m_pBuffer; }
		
		m_pBuffer = a_pBuffer;
		m_nSize = strlen(a_pBuffer);
	}

private:
	char* m_pBuffer = nullptr;
	size_t m_nSize = 0;
};


TempArr operator+(const TempArr& A, const TempArr& B)
{
	size_t nLen = A.Size() + B.Size();
	char* p = new char[nLen + 1];
	char* pTemp = p;

	strcpy_s(pTemp, nLen + 1, A.GetBuffer());
	pTemp += A.Size();

	strcpy_s(pTemp, nLen + 1 - A.Size(), B.GetBuffer());
	pTemp = nullptr;

	TempArr MyTempString;
	MyTempString.ReplaceBuffer(p);

	return MyTempString;
}


END_PRACTICE
