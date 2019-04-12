#include "pch.h"

#include "Practice/Day0009.h"


USING_PRACTICE

#include <cassert>


int main()
{
	using namespace std;

	SimpleQueue q;

	cout << q.Size() << endl;

	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);

	if (q.GetBufferSize() > q.Size())
	{
		q.Push(1);
		cout << "push" << endl;
	}

	cout << q.Size() << endl;


	q.Pop();
	cout << q.Size() << endl;

	q.Pop();
	cout << q.Size() << endl;

	q.Pop();
	cout << q.Size() << endl;

	for (int i = 0; i < 5; ++i)
	{
		int nSize = q.Size();
		cout << nSize << endl;

		if (q.GetBufferSize() > q.Size())
		{
			q.Push(1);
			cout << "push" << endl;
		}
		else
		{
			cout << "NoPush" << endl;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		if (q.GetBufferSize() > q.Size())
		{
			q.Push(1);
			cout << "push" << endl;
		}
		else
		{
			cout << "NoPush" << endl;
		}

		if (q.GetBufferSize() > q.Size())
		{
			q.Push(1);
			cout << "push" << endl;
		}
		else
		{
			cout << "NoPush" << endl;
		}

		if (q.GetBufferSize() > q.Size())
		{
			q.Push(1);
			cout << "push" << endl;
		}
		else
		{
			cout << "NoPush" << endl;
		}

		q.Pop();
	}
	

	getchar();
}