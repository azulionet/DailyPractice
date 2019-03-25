#pragma once

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>

#include <array>
#include <vector>
#include <list>
#include <string>
#include <cassert>
#include <algorithm>
#include <chrono>

#define BEGIN_PRACTICE	namespace Practice {
#define END_PRACTICE	}
#define USING_PRACTICE	using namespace Practice;

#define SAFE_DELETE(x)		{if(x!=nullptr){delete x; x = nullptr;}}

#if _DEBUG

	#define EXPECT_EQ(x,y) EXPECT_EQ_DBG(x,y)

#else

	#define EXPECT_EQ(x,y)

#endif


// 12 »¡°­, 15 °ËÁ¤, 10 ³ì»ö
#define EXPECT_EQ_DBG(x, y) \
{ \
 \
	auto h = GetStdHandle(STD_OUTPUT_HANDLE); \
	if( (x) != (y) ) \
	{ \
		SetConsoleTextAttribute(h, 12); \
		std::cout << " [--FAIL--] "; \
		SetConsoleTextAttribute(h, 15); \
		std::cout << "[LINE:" << setw(5) << __LINE__; \
		std::cout << "] : " << (x) << "is not same " << (y) << std::endl; \
	} \
	else \
	{ \
		SetConsoleTextAttribute(h, 10); \
		std::cout << " [--PASS--] "; \
		SetConsoleTextAttribute(h, 15); \
		std::cout << "[LINE:" << setw(5) << __LINE__; \
		std::cout << "]" << std::endl; \
	} \
}
