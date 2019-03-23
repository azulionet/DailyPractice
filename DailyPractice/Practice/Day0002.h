#pragma once

#include "DailyPractice/Define.h"
#include "DailyPractice/Component/PracticePool.h"

BEGIN_PRACTICE

template<typename T>
class LinkedList
{
	struct Node
	{
		T val;
		Node* pPrev = nullptr;
		Node* pNext = nullptr;

		Node(const T& a_val)
		{
			val = a_val;
		}
	};

public:

	LinkedList() = default;

	~LinkedList()
	{
		Clear();
	}

private:

	Node*	m_pHead = nullptr;
	Node*	m_pTail = nullptr;

public:

	void Add(const T& a_val)
	{
		if (m_pHead == nullptr)
		{
			m_pHead = new Node(a_val);
			m_pTail = m_pHead;
		}
		else
		{
			Node* pTemp = new Node(a_val);

			m_pTail->pNext = pTemp;
			pTemp->pPrev = m_pTail;

			m_pTail = pTemp;
		}
	}

	size_t Count() const
	{
		if (m_pHead == nullptr) { return 0; }

		Node* p = m_pHead;
		size_t nCount = 0;

		while (p != nullptr)
		{
			p = p->pNext;
			++nCount;
		}

		return nCount;
	}

	int Index(const T& a_val) const
	{
		Node* p = m_pHead;
		int nReturn = 0;

		while (p != nullptr)
		{
			if (p->val == a_val)
			{
				return nReturn;
			}

			p = p->pNext;
			++nReturn;
		}

		return -1;
	}

	Node* Find(const T& a_val) const
	{
		Node* p = m_pHead;

		while (p != nullptr)
		{
			if (p->val == a_val)
			{
				break;
			}

			p = p->pNext;
		}

		return p;
	}

	Node* RFind(const T& a_val) const
	{
		Node* p = m_pTail;

		while (p != nullptr)
		{
			if (p->val == a_val)
			{
				break;
			}

			p = p->pPrev;
		}

		return p;
	}

	bool Remove(const T& a_val)
	{
		Node* p = Find(a_val);

		if (p == nullptr) { return false; }

		Node* pPrev = p->pPrev;
		Node* pNext = p->pNext;

		if (pPrev != nullptr)
		{
			pPrev->pNext = pNext;
		}

		if (pNext != nullptr)
		{
			pNext->pPrev = pPrev;
		}

		ReturnObj(p);
	}

	void RemoveFirst()
	{
		if (m_pHead != nullptr)
		{
			Node* pTemp = m_pHead;
			m_pHead = m_pHead->pNext;
			ReturnObj(pTemp);
		}
	}

	void RemoveLast()
	{
		if (m_pHead != nullptr)
		{
			Node* pTemp = m_pHead;
			m_pHead = m_pHead->pNext;
			ReturnObj(pTemp);
		}
	}

	void Clear()
	{
		Node* p = m_pHead;
		Node* t = nullptr;

		while (p != nullptr)
		{
			t = p->pNext;
			ReturnObj(p);
			p = t;
		}

		m_pHead = nullptr;
		m_pTail = nullptr;
	}

	Node* GetFirst() const
	{
		if (m_pHead == nullptr) { throw; }

		return m_pHead;
	}

	Node* GetLast() const
	{
		if (m_pTail == nullptr) { throw; }

		return m_pTail;
	}

	void PopLast()
	{
		if (m_pTail == nullptr) { return; }

		Node* p = m_pTail;

		m_pTail = p->pPrev;

		ReturnObj(p);

		if (m_pTail == nullptr)
		{
			m_pHead = nullptr;
		}
	}

	void PopFirst()
	{
		if (m_pHead == nullptr) { return; }

		Node* p = m_pHead;

		m_pHead = m_pHead->Next;

		ReturnObj(p);

		if (m_pHead == nullptr)
		{
			m_pTail = nullptr;
		}
	}

	Node* Get(size_t a_n)
	{
		if (a_n >= Count())
		{
			return nullptr;
		}

		Node* p = m_pHead;

		for (int i = 0; i < a_n; ++i)
		{
			p = p->pNext;
		}		

		return p;
	}

	Node* RGet(size_t a_n)
	{
		if (a_n >= Count())
		{
			return nullptr;
		}

		Node* p = m_pTail;

		for (int i = 0; i < a_n; ++i)
		{
			p = p->pPrev;
		}

		return p;
	}

private:

	void ReturnObj(Node* a_pNode)
	{
		SAFE_DELETE(a_pNode);
	}
};

END_PRACTICE
