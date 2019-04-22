#pragma once

#include <vector>


template<typename T>
class ObjectPool
{
	ObjectPool(ObjectPool& pool) = delete;
	ObjectPool& operator=(const ObjectPool&) = delete;

public:

	ObjectPool(size_t a_nCreateCount = 0) : m_nMaxSize(a_nCreateCount)
	{
		m_Pool.resize(a_nCreateCount);
	}

	~ObjectPool()
	{
		for (auto val : m_Pool)
		{
			if (val != nullptr)
			{
				delete val;
			}
		}

		m_Pool.clear();
	}

	T* Get()
	{
		if (m_nNowCount == 0)
		{
			return new T();
		}

		--m_nNowCount;

		T* temp = m_Pool[m_nNowCount];
		m_Pool[m_nNowCount] = nullptr;

		return temp;
	}

	void Return(T* a_pRef)
	{
		if (a_pRef == nullptr) { return; }

		if (m_nNowCount == m_nMaxSize)
		{
			enum { eMake = 10, }; // 풀이 모자를 때 리사이징 추가 크기

			m_Pool.resize(m_nMaxSize + eMake);

			m_nMaxSize += eMake;
		}

		++m_nNowCount;
		m_Pool[m_nNowCount] = a_pRef;			
	}

	size_t GetFreeObjectCount() const
	{
		return m_nNowCount;
	}

	size_t GetMaxFreeObjectCount() const
	{
		return m_nMaxSize;
	}

private:
	std::vector<T*>	m_Pool;

	size_t			m_nMaxSize = 0;
	size_t			m_nNowCount = 0;
};
