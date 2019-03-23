#pragma once

#include <iostream>
#include "DailyPractice/Define.h"

BEGIN_PRACTICE

size_t Euclid(size_t a, size_t b)
{
	if (a == 0 || b == 0) { return 0; }

	while (b != 0)
	{
		if (a < b)
		{
			std::swap(a, b);
		}

		a = a - b;
	}

	return a;
}

size_t EuclidMod(size_t a, size_t b)
{
	if (a == 0 || b == 0) { return 0; }

	if (a < b)
	{
		std::swap(a, b);
	}

	while (b > 1)
	{
		a %= b;
		std::swap(a, b);
	}

	return a;
}

size_t EuclidNoStd(size_t a, size_t b)
{
	if (a == 0 || b == 0) { return 0; }

	size_t t;

	while (b > 0)
	{
		if (b > a)
		{
			a = b;
		}

		t = a - b;
	}

	return t;
}

size_t EuclidMod_NoStd(size_t a, size_t b)
{
	if (a == 0 || b == 0) { return 0; }

	size_t t;

	while (b > 0)
	{
		t = a % b;
		a = b;
		b = t;
	}

	return a;
}

END_PRACTICE
