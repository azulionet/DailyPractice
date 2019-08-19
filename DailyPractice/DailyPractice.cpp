#include "pch.h"

using namespace std;

#include "Day0026.h"
#include <numeric>

class A
{
public:
	void Print()
	{
		cout << "A" << endl;
	}
};

class B
{
public:
	virtual void Print()
	{
		cout << "A" << endl;
	}
};



template<typename T>
class EE
{
public:
	void Print()
	{
		cout << a << endl;
	}
	
	T a;
};


template<>
class EE<double> : public B
{
public:

	virtual void Print() override
	{
		B::Print();
		cout << "A" << endl;
	}


};


#include <type_traits>


template<typename _Void, typename T>
struct has_length : std::false_type {};

template<typename T>
struct has_length<void_t<decltype(std::declval<T>().size())>, T> : std::true_type {};

template<typename T>
using use_length = has_length<void, T>;

template<typename T>
using use_length_t = typename use_length<T>::type;


template<typename T>
int GetVal_Impl(std::false_type, T val)
{
	cout << "int" << endl;
	return (int)val;

}
template<typename T>
int GetVal_Impl(std::true_type, T val)
{
	cout << "size" << endl;
	return val.size();
}




template<typename T>
int GetVal(T val)
{
	return GetVal_Impl<T>(use_length_t<T>{}, val);
}


/*
template<typename T, bool b>
size_t _GetSize(T a)
{
	return (size_t)a;
}


template<typename T>
size_t _GetSize<true>(T a)
{
	return (size_t)a.length();
}


template<typename T>
size_t GetSize(T a)
{
	return _GetSize<T, has_length<T>>(a);
}
*/





int main()
{
	cout << GetVal(10) << endl;
	cout << GetVal(10.3) << endl;

	std::vector<int> a{ 1,3,5,6,4 };

	cout << GetVal(a) << endl;

	

	getchar();
	return 0;
}

