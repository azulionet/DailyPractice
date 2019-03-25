#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cassert>
#include <algorithm>

#define BEGIN_PRACTICE	namespace Practice {
#define END_PRACTICE	}
#define USING_PRACTICE	using namespace Practice;

#define SAFE_DELETE(x)		{if(x!=nullptr){delete x; x = nullptr;}}
#define SAFE_DELETE_ARR(x)	{if(x!=nullptr){delete[] x; x = nullptr;}}
