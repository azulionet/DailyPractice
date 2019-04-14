#include "pch.h"

#include "Practice/Day_0010.h"


USING_PRACTICE

#include <cassert>

constexpr float MySqrt(float a_fInput)
{
	float x = 1.0f;

	for (int i = 0; i < 20; ++i)
	{
		x = (x + (a_fInput / x)) / 2;
	}

	return x;
}



#include <random>

int main()
{
	using namespace std;

	cout << sequenceElement2({ 7,5,4,4,8 }, 521687676) << endl;

	/*
	cout << FindRepeat({ 1,1,1,0}, [](int* p, int n)
	{
		n %= 4;

		return n == 3 ? 0 : 1;
	}
	) << endl;

	cout << FindRepeat({ 1,2,3,4,5 },
		[](int* p, int n)
		{
			p += n;		
			return (p[-1] + p[-2] + p[-3] + p[-4] + p[-5]) %10;
		}
	) << endl;
	*/


	getchar();
}