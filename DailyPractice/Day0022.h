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


struct Test_Struct_Explicit
{
public:
	explicit Test_Struct_Explicit(int a, int b) : _a(a), _b(b) { cout << "creator" << endl; }
	explicit Test_Struct_Explicit(Test_Struct_Explicit&& v) : _a(v._a), _b(v._b) { cout << "&&" << endl; }
	explicit Test_Struct_Explicit(const Test_Struct_Explicit& v) : _a(v._a), _b(v._b) { cout << "&" << endl; }

	int GetA() const { return _a; }

	int _a;
	int _b;
};


struct Test_Struct_NoExcept_Explicit
{
public:
	explicit Test_Struct_NoExcept_Explicit(int a, int b) noexcept : _a(a), _b(b) { cout << "creator" << endl; }
	explicit Test_Struct_NoExcept_Explicit(Test_Struct_NoExcept_Explicit&& v) noexcept : _a(v._a), _b(v._b) { cout << "&&" << endl; }
	explicit Test_Struct_NoExcept_Explicit(const Test_Struct_NoExcept_Explicit& v) noexcept : _a(v._a), _b(v._b) { cout << "&" << endl; }

	int GetA() const { return _a; }

	int _a;
	int _b;
};



class Test_Class_NoOption
{
public:
	Test_Class_NoOption(int a, int b) : _a(a), _b(b) { cout << "creator" << endl; }
	Test_Class_NoOption(Test_Class_NoOption&& v) : _a(v._a), _b(v._b) { cout << "&&" << endl; }
	Test_Class_NoOption(const Test_Class_NoOption& v) : _a(v._a), _b(v._b) { cout << "&" << endl; }

	int GetA() const { return _a; }

	int _a;
	int _b;
};


class Test_Class_NoExcept
{
public:
	Test_Class_NoExcept(int a, int b) noexcept : _a(a), _b(b) { cout << "creator" << endl; }
	Test_Class_NoExcept(Test_Class_NoExcept&& v) noexcept : _a(v._a), _b(v._b) { cout << "&&" << endl; }
	Test_Class_NoExcept(const Test_Class_NoExcept& v) noexcept : _a(v._a), _b(v._b) { cout << "&" << endl; }

	int GetA() const { return _a; }

	int _a;
	int _b;
};


class Test_Class_Explicit
{
public:
	explicit Test_Class_Explicit(int a, int b) : _a(a), _b(b) { cout << "creator" << endl; }
	explicit Test_Class_Explicit(Test_Class_Explicit&& v) : _a(v._a), _b(v._b) { cout << "&&" << endl; }
	explicit Test_Class_Explicit(const Test_Class_Explicit& v) : _a(v._a), _b(v._b) { cout << "&" << endl; }

	int GetA() const { return _a; }

	int _a;
	int _b;
};


class Test_Class_NoExcept_Explicit
{
public:
	explicit Test_Class_NoExcept_Explicit(int a, int b) noexcept : _a(a), _b(b) { cout << "creator" << endl; }
	explicit Test_Class_NoExcept_Explicit(Test_Class_NoExcept_Explicit&& v) noexcept : _a(v._a), _b(v._b) { cout << "&&" << endl; }
	explicit Test_Class_NoExcept_Explicit(const Test_Class_NoExcept_Explicit& v) noexcept : _a(v._a), _b(v._b) { cout << "&" << endl; }

	int GetA() const { return _a; }

	int _a;
	int _b;
};

