#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

template <typename T>
class BinaryTree
{
public:

	struct BNode
	{
		BNode(const T& val) : v(val) {}

		T v;
		BNode* l = nullptr;
		BNode* r = nullptr;

		void AddLeft(const T& a_val)
		{
			if (l != nullptr)
			{
				throw;
			}

			l = new BNode(a_val);
		}

		void AddRight(const T& a_val)
		{
			if (r != nullptr)
			{
				throw;
			}

			r = new BNode(a_val);
		}
	};

	~BinaryTree()
	{
		Clear();
	}

public: // 인터페이스

	void Clear()
	{
		if (m_pRoot == nullptr) { return; }

		std::queue<BNode*> q;
		q.push(m_pRoot);

		while (q.size() > 0)
		{
			auto * p = q.front();
			q.pop();

			if (p == nullptr) { continue; }

			q.push(p->l);
			q.push(p->r);

			SAFE_DELETE(p);
		}

		m_pRoot = nullptr;
	}

	void AddValue(const T& a_val)
	{
		if (m_pRoot == nullptr)
		{
			m_pRoot = new BNode(a_val);
		}
		else
		{
			BNode* pTarget = m_pRoot;
			bool bLeft;

			while (pTarget != nullptr)
			{
				if (pTarget->v > a_val)
				{
					bLeft = false;

					if (pTarget->r == nullptr)
					{
						break;
					}
					else
					{
						pTarget = pTarget->r;
					}
				}
				else
				{
					bLeft = true;

					if (pTarget->l == nullptr)
					{
						break;
					}
					else
					{
						pTarget = pTarget->l;
					}
				}
			}

			if (bLeft == true)
			{
				pTarget->AddLeft(a_val);
			}
			else
			{
				pTarget->AddRight(a_val);
			}
		}
	}

	void Recursive_TreeTraversal_PreOrder(BNode* pNode)
	{
		if (pNode == nullptr) { return; }

		Visit(pNode);
		Recursive_TreeTraversal_PreOrder(pNode->l);
		Recursive_TreeTraversal_PreOrder(pNode->r);
	}

	void Recursive_TreeTraversal_PostOrder(BNode* pNode)
	{
		if (pNode == nullptr) { return; }

		Recursive_TreeTraversal_PostOrder(pNode->l);
		Recursive_TreeTraversal_PostOrder(pNode->r);
		Visit(pNode);
	}

	void Recursive_TreeTraversal_InOrder(BNode* pNode)
	{
		if (pNode == nullptr) { return; }

		Recursive_TreeTraversal_InOrder(pNode->l);
		Visit(pNode);
		Recursive_TreeTraversal_InOrder(pNode->r);
	}	

	void Stack_TreeTraversal_InOrder(BNode* pNode)
	{
		if (pNode == nullptr) { return; }

		std::stack<BNode*> s;

		BNode* pTemp = pNode;

		s.push(pTemp);

		while (pTemp->l != nullptr)
		{
			s.push(pTemp->l);
			pTemp = pTemp->l;
		}
		
		pTemp = s.top();

		while (true)
		{
			Visit(pTemp);
			s.pop();

			if (pTemp->r != nullptr)
			{
				s.push(pTemp->r);

				// 다시 집어넣은 R의 모든 L 차일드를 전부 다시 집어넣음
				if (pTemp->r->l != nullptr)
				{
					BNode* pR = pTemp->r->l;
					while (pR != nullptr)
					{
						s.push(pR);
						pR = pR->l;
					}
				}
			}

			if (s.size() == 0)
			{
				break;
			}

			pTemp = s.top();			
		}
	}

	void Visit(BNode* a_pNode)
	{
		if (a_pNode == nullptr)
		{
			throw;
		}

		std::cout << a_pNode->v << std::endl;
	}

public:

	BNode* m_pRoot = nullptr;
};

END_PRACTICE
