#pragma once

#include <iostream>
#include <string>

using namespace std;

#define BEGIN_TEST(ClassName, Num) class ClassName##Num \
{ \
public: \
 ClassName##Num() { UnitTest(); } \
 void UnitTest() {

#define END_TEST() }};

#define SAFE_DELETE(x)		{if(x!=nullptr){delete x; x = nullptr;}}
#define SAFE_DELETE_ARR(x)	{if(x!=nullptr){delete[] x; x = nullptr;}}
