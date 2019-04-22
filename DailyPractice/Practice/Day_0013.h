#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

template <typename T>
class SmartPointer
{
	SmartPointer(T* a_pMemory)
	{
		m_pMemory = a_pMemory;
	}

	~SmartPointer()
	{
		SAFE_DELETE(m_pMemory);
	}

	T * m_pMemory = nullptr;
};


END_PRACTICE
