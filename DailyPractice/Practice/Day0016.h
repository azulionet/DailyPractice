#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

template<typename T>
class LinkedList
{
public:

	struct Node
	{
		Node(const T& v) { val = v; }
		T val;
		Node * next = nullptr;
	};

	LinkedList() = default;
	LinkedList(std::initializer_list<T> a)
	{
		for (auto val : a)
		{
			Add(val);
		}
	}

	~LinkedList()
	{
		Clear();			
	}

	Node* m_pHead = nullptr;

	void Add(const T& a)
	{
		Node* temp = new Node{ a };

		if (m_pHead == nullptr)
		{
			m_pHead = temp;
		}
		else
		{
			Node* p = m_pHead;

			while (p->next != nullptr)
			{
				p = p->next;
			}

			p->next = temp;
		}
	}

	bool Remove(const T& a)
	{
		Node* p = m_pHead;
		Node* prev = nullptr;

		while (p != nullptr)
		{
			if (p->val == a)
			{
				if (prev != nullptr)
				{
					prev->next = p->next;
				}

				if (m_pHead == p)
				{
					m_pHead = nullptr;
				}

				delete p;
				return true;
			}

			prev = p;
			p = p->next;
		}

		return false;
	}

	bool Find(const T& a)
	{
		Node* p = m_pHead;

		while (p != nullptr)
		{
			if (p->val == a)
			{
				return true;
			}

			p = p->next;
		}

		return false;
	}

	int Count()
	{
		Node* p = m_pHead;
		int nCount = 0;

		while (p != nullptr)
		{
			++nCount;
			p = p->next;
		}

		return nCount;
	}

	bool Empty()
	{
		return m_pHead == nullptr;
	}

	void Clear()
	{
		Node* p = m_pHead;

		while (p != nullptr)
		{
			Node* temp = p->next;
			delete p;
			p = temp;
		}

		m_pHead = nullptr;
	}
};

using namespace  std;


class Ref
{
public:

	Ref(std::string&& s) noexcept	{ cout << "&& ctor" << endl; mStr = std::move(s); }
	Ref(const std::string& s)		{ cout << "&ctor" << endl; mStr = s; }

	// int A() & { std::cout << __FUNCTION__ << " : " << "&" << std::endl; return m_nData; }
	int A() const& { std::cout << __FUNCTION__ << " : " << "const &" << std::endl; return m_nData; }
	int A() && { std::cout << __FUNCTION__ << " : " << "&&" << std::endl; return m_nData; }

	// &&버전 없을시
	// const std::string& Str() const	{ cout << "const" << endl;  return mStr; }
	// std::string&& Str()				{ cout << "&&" << endl;  return std::move(mStr); }

	// &&버전 존재
	const std::string& Str() const&		{ cout << "const" << endl;  return mStr; }
	std::string&& Str() &				{ cout << "&&" << endl;  return std::move(mStr); }
	std::string&& Str() &&				{ cout << "&&" << endl;  return std::move(mStr); }

	std::string mStr = "hello";
	int m_nData = 0;
};



END_PRACTICE
