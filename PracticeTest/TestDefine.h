#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define BEGIN_TEST(ClassName, Num) class ClassName##Num \
{ \
public: \
 ClassName##Num() { UnitTest(); } \
 void UnitTest() {

#define END_TEST() }};

#define SAFE_DELETE(x)		{if(x!=nullptr){delete x; x = nullptr;}}
#define SAFE_DELETE_ARR(x)	{if(x!=nullptr){delete[] x; x = nullptr;}}

// constexpr 테스트용 클래스
template<int n>
struct constN
{
	constN() { std::cout << N << '\n'; }
};
