#pragma once
#include "pch.h"

struct Test_Struct_NoOption
{
public:
	Test_Struct_NoOption(int a, int b) : _a(a), _b(b) { cout << "creator" << endl; }
	Test_Struct_NoOption(Test_Struct_NoOption&& v) : _a(v._a), _b(v._b) { cout << "&&" << endl; }
	Test_Struct_NoOption(const Test_Struct_NoOption& v) : _a(v._a), _b(v._b) { cout << "&" << endl; }

	int GetA() const { return _a; }

	int _a;
	int _b;
};


struct Test_Struct_NoExcept
{
public:
	Test_Struct_NoExcept(int a, int b) noexcept : _a(a), _b(b) { cout << "creator" << endl; }
	Test_Struct_NoExcept(Test_Struct_NoExcept&& v) noexcept : _a(v._a), _b(v._b) { cout << "&&" << endl; }
	Test_Struct_NoExcept(const Test_Struct_NoExcept& v) noexcept : _a(v._a), _b(v._b) { cout << "&" << endl; }

	int GetA() const { return _a; }

	int _a;
	int _b;
};

