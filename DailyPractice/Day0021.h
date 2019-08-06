#pragma once

// 템플릿 푸랜드 함수 클래스 내부정의

template<typename T>
class FriendTest
{
public:

	T a;

	friend std::ostream& operator<<(std::ostream& o, const FriendTest<T>& out)
	{
		o << out.a;
		return o;
	}
};


template<typename T>
void TestPrint(T arg)
{
	std::cout << arg << std::endl;
}

template<typename T, typename... Types>
void TestPrint(T arg, Types... as)
{
	std::cout << arg << std::endl;
	TestPrint(as...);
}




