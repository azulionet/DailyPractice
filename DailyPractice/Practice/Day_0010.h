#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

const int nSameCount = 100;

typedef int(*fpNextVal)(int*, int);

constexpr int ProblemBuffer()
{
	return 4;
}

int GetNextValue(int* p, int nIndex)
{
	return p[-1] + p[-2] + p[-3] + p[-4] + p[-5];
}

unsigned int FindRepeat(std::vector<int> vc, fpNextVal a_fpGetValue)
{
	enum { 
		eMAX_ARRAY = 100000,
		eMAX_ARRAY_SIZE = eMAX_ARRAY + ProblemBuffer() }; // 이 갯수 이상일 경우 훡유하고 풀지 않겠다. 

	int ar[eMAX_ARRAY_SIZE] = { 0, };
	int nReturn = 0;
	int nCount = vc.size();
	int nSameCount = 0;

	for (int i = 0; i < nCount; ++i)
	{
		ar[i] = vc[i];
	}

	for (int i = nCount; i<eMAX_ARRAY; ++i )
	{
		ar[i] = a_fpGetValue(ar, i);
	}

	int* p1 = ar;

	for (int j = 1; j < eMAX_ARRAY / 2; ++j)
	{
		int* p2 = ar + j;

		if (*p1 == *p2)
		{
			int nGap = p2 - p1;
			bool bCheck = true;

			for (int k = j ; k < eMAX_ARRAY / 2 - nGap; k += nGap)
			{
				int *pK = ar + k;

				for (int l = 0; l < nGap; ++l)
				{
					if (pK[l] != p1[l])
					{
						goto NOT_MATCHED;
					}
				}
			}

			if (bCheck == true)
			{
				return j;
			}
		}
	NOT_MATCHED:;
	}

	return -1;
}

int sequenceElement(std::vector<int> ar, int n)
{
	if (n <= 4) { return ar[n]; }

	int a[5] = { ar[0], ar[1], ar[2], ar[3], ar[4] };

	int nIndex = 0;
	int nSum = 0;
	int nResult = a[0] + a[1] + a[2] + a[3] + a[4];
	int nTemp = a[0];

	nResult %= 10;
	nSum = a[nIndex] = nResult;
	nResult -= nTemp;

	for (int i = 5; i <= n; ++i)
	{
		nResult += nSum;

		++nIndex;
		nIndex %= 5;

		nTemp = a[nIndex];
		
		nResult += 10;
		nResult %= 10;

		nSum = a[nIndex] = nResult;

		nResult -= nTemp;
	}

	nIndex += 4; // += 5, -1
	nIndex %= 5;

	return a[nIndex];
}




int sequenceElement2(std::vector<int> ar, int n)
{
	if (n <= 4) { return ar[n]; }

	enum { Gap = 4686 };
	int a[Gap] = { ar[0], ar[1], ar[2], ar[3], ar[4], };

	n %= Gap;

	for (int i = 5; i<=n; ++i )
	{
		a[i] = (a[i - 5] + a[i - 4] + a[i - 3] + a[i - 2] + a[i - 1])%10;
	}

	return a[n];
}






END_PRACTICE
