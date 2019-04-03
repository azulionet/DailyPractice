#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

using namespace std;

void Copy(std::vector<int>& a, std::vector<int>& b)
{
	b.clear();
	std::unique_copy(begin(a), end(a), std::back_inserter(b));
}

void UniqueCopy(std::vector<int>& a, std::vector<int>& b)
{
	b.clear();

	std::sort(std::begin(a), std::end(a));
	std::unique_copy(begin(a), end(a), std::back_inserter(b));
}


template<typename T, typename V>
static std::vector<typename T::iterator> FindAll(T& a_Container, const V& a_val)
{
	std::vector<typename T::iterator> vc;

	auto itor = a_Container.begin();

	for(; itor != a_Container.end(); ++itor )
	{
		if ((*itor) == a_val)
		{
			vc.push_back(itor);
		}
	}
	
	return vc;
}

void PrintTwoWord(const char* s0, const char* s1)
{
	std::ostream_iterator<string> cout{std::cout};

	*cout = s0;
	// ++cout;

	*cout = s1;
	*cout = "\n";
}

int FileIO()
{
	string from = "test.txt";
	string to = "test2.txt";

	ifstream is{ from };
	
	istream_iterator<string> ii{ is };
	istream_iterator<string> eos{};

	ofstream os{ to };
	ostream_iterator<string> oo{ os, "\n" };

	vector<string> b{ ii, eos };
	sort(b.begin(), b.end());

	unique_copy(b.begin(), b.end(), oo);

	return !is.eof() || !os;
}

int FileIO2()
{
	ifstream is{ "test.txt" };
	ofstream os{ "test2.txt" };

	std::vector<string> set{ istream_iterator<string>{is}, istream_iterator<string>{} };
	copy(set.begin(), set.end(), ostream_iterator<string>{os, "\n"});

	return !is.eof() || !os;
}


class A
{
public:
	A() = default;
	~A()
	{
		cout << "A Dtor" << endl;
	}
};

class B
{
public:
	B() = default;
	~B()
	{
		cout << "B Dtor" << endl;
	}

	A a;
};





END_PRACTICE
