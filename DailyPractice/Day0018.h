#pragma once



#define T(Num) void TEST##0018_## Num () {
#define Test(Num) TEST##0018_## Num()
#define END }


template<typename T, typename Container = std::vector<T>>
class MyStack
{
public:

	using Iter = typename Container::iterator;
	using type = typename T;

	Iter begin()
	{
		return m_Val.begin();
	}

	Iter end()
	{
		return m_Val.end();
	}

	void Push(const T& val)
	{
		m_Val.push_back(val);
	}

	void Pop()
	{
		m_Val.pop_back();
	}

	void Peek()
	{
		m_Val.back();
	}

	size_t Size()
	{
		return m_Val.size();
	}



	Container m_Val;
};


// #define PracitceStart(Num, FileNumber) TEST_ ## Num ## fileNumber
// #define TEST_0(t, f) f
// #define TEST_1(t, f) t





T(1)

MyStack<int> s;

s.Push(1);
s.Push(2);
s.Push(3);
s.Push(4);
s.Push(5);

for (auto& val : s)
{
	cout << val << endl;
}

END


T(2)

MyStack<int, std::deque<int>> a;

a.Push(1);
a.Push(2);
a.Push(3);
a.Push(4);
a.Push(5);

for (auto& val : a)
{
	cout << val << endl;
}

END