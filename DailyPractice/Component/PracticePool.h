#pragma once


template<typename T>
class Pool
{

#pragma region _SINGLE_TON_

private:
	Pool(size_t a_nCount)
	{
		ResizePool(a_nCount);
	}

	static Pool* m_pInstance;

public:

	static inline void Instancing(size_t a_nCount)
	{
		if (m_pInstance != nullptr)
		{
			return;
		}

		m_pInstance = new Pool(a_nCount);
	}

	static inline Pool* GetInstance()
	{
		return m_pInstance;
	}

	static inline void ReleaseInstnace()
	{
		SAFE_DELETE(m_pInstance);
	}

#pragma endregion

private:

	std::vector<T*> m_objPool;
	size_t			m_Size;

public:

	size_t Size()
	{
		return m_Size;
	}

	void ResizePool(size_t a_nCount)
	{
		m_objPool.resize(a_nCount);
	}

	void Return(T* a_p)
	{
		m_objPool.Add(a_p);
	}
};

template<typename T>
Pool<T>* Pool<T>::m_pInstance = nullptr;

#define InstancingPool(TypeName, Count)	{ Pool<TypeName>::Instancing(Count); }
#define GetPool(TypeName)				{ Pool<TypeName>::GetInstance(); }
#define ReleasePool(TypeName)			{ Pool<TypeName>::ReleaseInstnace(); }



template<typename T>
class Pooler;

class IPool
{
public:
	typedef int IPoolDerived;

	// 자기 자신 리턴
	virtual void Return(IPool* a_pThis) = 0;
};

template<typename T>
class Pooler : Pool<T>
{
#pragma region _SINGLE_TON_

private:
	Pooler(size_t a_nCount)
	{
		// AddPool(a_nCount);
	}

	static Pooler* m_pInstance;

public:

	static inline void Instancing(size_t a_nCount)
	{
		if (m_pInstance != nullptr)
		{
			return;
		}

		m_pInstance = new Pooler(a_nCount);
	}

	static inline Pooler* GetInstance()
	{
		return m_pInstance;
	}

	static inline void ReleaseInstnace()
	{
		SAFE_DELETE(m_pInstance);
	}

#pragma endregion

	// typedef T::IPoolDerived IPoolInterfaceGuard;
};


#define InstancingPool(TypeName, Count)	{ Pooler<TypeName>::Instancing(Count); }
#define GetPool(TypeName)				{ Pooler<TypeName>::GetInstance(); }
#define ReleasePool(TypeName)			{ Pooler<TypeName>::ReleaseInstnace(); }
