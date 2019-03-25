#pragma once

#include "DailyPractice/Define.h"
#include "DailyPractice/Component/PracticePool.h"

BEGIN_PRACTICE

// https ://app.codesignal.com/arcade/intro/level-2/bq2XnSr5kbHqpHGJC
int makeArrayConsecutive2(std::vector<int> statues)
{
	auto val = std::minmax_element(std::begin(statues), std::end(statues));

	size_t n = std::abs(*val.second - *val.first);

	
	return n - statues.size() + 1;
}








// constexpr int CONST_EXPR_makeArrayConsecutive2(const int[] statues, const int b)
// {
// 	int nMin = INT_MAX;
// 	int nMax = INT_MIN;
// 	int nSize = b;
// 
// 	for (int i = 0; i < nSize; ++i)
// 	{
// 		if (statues[i] > nMax)
// 		{
// 			nMax = statues[i];
// 		}
// 
// 		if (statues[i] < nMin)
// 		{
// 			nMin = statues[i];
// 		}
// 	}
// 
// 	return nMax - nMin - nSize + 1;
// }





END_PRACTICE
