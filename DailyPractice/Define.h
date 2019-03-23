#pragma once

#define BEGIN_PRACTICE	namespace Practice {
#define END_PRACTICE	}
#define USING_PRACTICE	using namespace Practice;

#define SAFE_DELETE(x)		{if(x!=nullptr){delete x; x = nullptr;}}
#define SAFE_DELETE_ARR(x)	{if(x!=nullptr){delete[] x; x = nullptr;}}
