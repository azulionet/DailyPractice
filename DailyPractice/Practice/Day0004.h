#pragma once

#include "DailyPractice/Define.h"
#include "DailyPractice/Component/PracticePool.h"

BEGIN_PRACTICE

// https ://app.codesignal.com/challenge/cksc3cndoKiuZhe6Y

/*
Given a divisor and a bound, find the largest integer N such that:

N is divisible by divisor.
N is less than or equal to bound.
N is greater than 0.
It is guaranteed that such a number exists.

Example

For divisor = 3 and bound = 10, the output should be
maxMultiple(divisor, bound) = 9.

The largest integer divisible by 3 and not larger than 10 is 9.

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] integer divisor

Guaranteed constraints:
2 ¡Â divisor ¡Â 10.

[input] integer bound

Guaranteed constraints:
5 ¡Â bound ¡Â 100.

[output] integer

The largest integer not greater than bound that is divisible by divisor.
*/
int maxMultiple(int divisor, int bound)
{
	return bound - bound % divisor;
}


/* https://app.codesignal.com/challenge/mrAXkgwfH5a9HCyuL
Given an array a and an integer d, find two elements of the array such that their absolute difference is not greater than d but is as close to d as possible (there may be more than one such pair). Return the absolute difference between these two elements or -1 if no suitable pairs were found.

Example

For a = [3, 2, 1] and d = 2, the output should be
differentValues(a, d) = 2;
For a = [3, 7] and d = 3, the output should be
differentValues(a, d) = -1.
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer a

Array of different integers.

Guaranteed constraints:
2 ¡Â a.length ¡Â 10,
-40 ¡Â a[i] ¡Â 40.

[input] integer d

A positive integer.

Guaranteed constraints:
2 ¡Â d ¡Â 10.

[output] integer

The best possible absolute difference or -1 if no suitable pairs were found.
*/
int differentValues(std::vector<int> a, int d)
{
	int nResult = -50;
	int nSize = a.size();
	
	for (int i = 0; i < nSize-1; ++i)
	{
		for (int j = i + 1; j < nSize; ++j)
		{
			int nTemp = std::abs(a[i] - a[j]);

			if (nTemp == d)
			{
				return d;
			}
			else if( nTemp < d )
			{
				if (std::abs(nResult - d) > std::abs(nTemp - d))
				{
					nResult = nTemp;
				}
			}
		}
	}

	return nResult == -50 ? -1 : nResult;
}



END_PRACTICE
