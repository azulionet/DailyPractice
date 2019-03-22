#pragma once


template<typename T>
class Pool
{

#pragma region _SINGLE_TON_

private:
	Pool(size_t a_nCount)
	{
		AddPool(a_nCount);
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

	void Print()
	{
		std::cout << typeid(T).name() << std::endl;
	}

	size_t Size()
	{
		return m_Size;
	}

	void AddPool(size_t a_nCount)
	{
		std::cout << __FUNCTION__ << std::endl;
		std::cout << "count: " << a_nCount << std::endl;
	}
};

template<typename T>
Pool<T>* Pool<T>::m_pInstance = nullptr;

#define InstancingPool(TypeName, Count)	{ Pool<TypeName>::Instancing(Count); }
#define GetPool(TypeName)				{ Pool<TypeName>::GetInstance(); }
#define ReleasePool(TypeName)			{ Pool<TypeName>::ReleaseInstnace(); }
