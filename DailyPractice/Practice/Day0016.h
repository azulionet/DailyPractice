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

END_PRACTICE
