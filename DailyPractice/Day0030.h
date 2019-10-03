#pragma once

#include <iostream>

using std::cout;
using std::endl;

#ifndef SAFE_DELETE
	#define SAFE_DELETE(x) { if((x)!=nullptr) { delete (x); (x) = nullptr;} }
#endif

struct Node
{
	Node(int val) : v(val) {}
	~Node()
	{
		SAFE_DELETE(l);
		SAFE_DELETE(r);
	}

	void Visit() { cout << "visit : " << v << endl; }

	Node* l = nullptr;
	Node* r = nullptr;
	int v = 0;
};

struct Comp
{
	virtual bool operator()(int a, int b) const = 0;
};

struct Less : Comp
{
	// Comp을(를) 통해 상속됨
	virtual bool operator()(int a, int b) const override
	{
		return a < b;
	}
};

struct Greater : Comp
{
	// Comp을(를) 통해 상속됨
	virtual bool operator()(int a, int b) const override
	{
		return a > b;
	}
};

struct Tree
{
	Node* h = nullptr;

	~Tree()
	{
		SAFE_DELETE(h);
	}

	void Add_Plain(int v, const Comp& comp = Less{})
	{
		Node** pTemp = &h;

		while (*pTemp != nullptr)
		{
			Node* pNode = *pTemp;

			if (pNode->v == v)
			{
				cout << "same value" << v << endl;
				return;
			}

			comp(v, pNode->v) ? (pTemp = &pNode->l) : (pTemp = &pNode->r);
		}
		
		if (*pTemp == nullptr)
		{
			*pTemp = new Node(v);
			return;
		}
	}

	Node* Find(int v)
	{
		return NodeFind(h, v);
	}

	int GetLevel(Node* p)
	{
		return GetRelativeLevel(h, p);
	}

	Node* GetParent(Node* p)
	{
		return NodeParent(h, p);
	}

	Node* FindLeastCommonAncestor(int a, int b)
	{
		if (a == b) { cout << "check arg" << endl; return false; }

		Node* p1 = Find(a);
		Node* p2 = Find(b);

		if (p1 == nullptr || p2 == nullptr) { return nullptr; }

		int n1 = GetLevel(p1);
		int n2 = GetLevel(p2);
		int nLeast = n2 > n1 ? n1 : n2;

		while (nLeast < n1) { p1 = GetParent(p1); --n1; }
		while (nLeast < n2) { p2 = GetParent(p2); --n2; }

		while (p1 != p2)
		{
			p1 = GetParent(p1);
			p2 = GetParent(p2);
		}

		return p1;
	}

	static void PrintPreOrder(Node* p)
	{
		if (p == nullptr) { return; }

		p->Visit();
		PrintPreOrder(p->l);
		PrintPreOrder(p->r);
	}

	static void PrintPostOrder(Node* p)
	{
		if (p == nullptr) { return; }

		PrintPreOrder(p->l);
		PrintPreOrder(p->r);
		p->Visit();
	}

	static void PrintInOrder(Node* p)
	{
		if (p == nullptr) { return; }

		PrintPreOrder(p->l);
		p->Visit();
		PrintPreOrder(p->r);
	}

	static Node* NodeFind(Node* r, int v, const Comp& comp = Less{})
	{
		if (r == nullptr) { return nullptr; }

		Node* pTemp = r;

		while (pTemp != nullptr)
		{
			if (pTemp->v == v)
			{
				return pTemp;
			}

			comp(v, pTemp->v) ? pTemp = pTemp->l : pTemp = pTemp->r;
		}
	
		return nullptr;
	}

	static Node* NodeParent(Node* r, Node* c, const Comp& comp = Less{})
	{
		if (r == nullptr || c == nullptr ) { return nullptr; }

		Node* pTemp = r;

		while (pTemp != nullptr)
		{
			r = pTemp;
			pTemp = comp(c->v, pTemp->v) ? pTemp->l : pTemp->r;

			if (pTemp == c)
			{
				return r;
			}
		}

		return nullptr;
	}

	static int GetRelativeLevel(Node* r, Node* t, const Comp& comp = Less{})
	{
		if (r == nullptr || t == nullptr) { cout << "check arg" << endl;  return -1; }

		Node* pTemp = r;
		int n = 0;

		while (pTemp != nullptr)
		{
			if (pTemp->v == t->v)
			{
				return n;
			}

			++n;
			comp(t->v, pTemp->v) ? pTemp = pTemp->l : pTemp = pTemp->r;
		}

		return -1;
	}



};



