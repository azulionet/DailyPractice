#pragma once

template<typename T>
class TestSimpleAutoPtr
{
public:
	explicit SmartPtr(T* a_pMemory) : m_Pointer(a_pMemory) {}
	
	SmartPtr(const SmartPtr<T>&) = delete;
	SmartPtr(SmartPtr<T>&&) = delete;
	
	~SmartPtr() { SAFE_DELETE(a_pMemory); }

	T& operator*() { return m_Pointer; }
	T* operator->() { return *m_Pointer; }

private:
	T* m_Pointer = nullptr;
};

template<typename T>
class TestSimpleSharedPtr
{
public:
	
	TestSimpleSharedPtr() noexcept : m_Pointer(nullptr), m_pReferenceCount(nullptr) { }
	TestSimpleSharedPtr(nullptr_t t) noexcept : m_Pointer(nullptr), m_pReferenceCount(nullptr) { }

	explicit TestSimpleSharedPtr(T* a_pMemory) : m_Pointer(a_pMemory), m_pReferenceCount(nullptr)
	{
		if (a_pMemory)
		{
			m_pReferenceCount = new int(1);
		}
	}

	explicit TestSimpleSharedPtr(const TestSimpleSharedPtr<T>& a) :
		m_Pointer(a.m_Pointer), m_pReferenceCount(a.m_pReferenceCount)
	{
		if (m_pReferenceCount != nullptr)
		{
			++(*m_pReferenceCount);
		}
	}

	TestSimpleSharedPtr(SmartPtr&&) = delete;

	~TestSimpleSharedPtr()
	{
		Decrease();
	}

	TestSimpleSharedPtr& operator=(const TestSimpleSharedPtr& c)
	{
		Decrease();

		m_Pointer = c->m_Pointer;
		m_pReferenceCount = c->m_pReferenceCount;

		if (m_pReferenceCount != nullptr)
		{
			++(*m_pReferenceCount);
		}

		return *this;
	}

	TestSimpleSharedPtr& operator=(nullptr_t null)
	{
		Decrease();

		m_Pointer = nullptr;
		m_pReferenceCount = nullptr;

		return *this;
	}
	
	T& operator*() const { return m_Pointer; }
	T* operator->() const { return *m_Pointer; }

	int ReferenceCount() { return (m_pReferenceCount == nullptr) ? 0 : *m_pReferenceCount; }

private:

	void Decrease()
	{
		if (m_pReferenceCount != nullptr)
		{
			--(*m_pReferenceCount);

			if (*m_pReferenceCount == 0)
			{
				SAFE_DELETE(m_Pointer);
				SAFE_DELETE(m_pReferenceCount);
			}
		}
	}

private:
	T* m_Pointer;
	int* m_pReferenceCount;
};
