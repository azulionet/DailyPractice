#pragma once

#include "DailyPractice/Practice/Day0003.h"

USING_PRACTICE

BEGIN_TEST(Day, 3)
{
	EXPECT_EQ(makeArrayConsecutive2({ 6, 2, 3, 8 }), 3);
	EXPECT_EQ(makeArrayConsecutive2({ 0, 4 }), 3);


	std::vector<int> v = { 3, 9, 1, 4, 2, 5, 9 };
	auto val = std::minmax_element(std::begin(v), std::end(v));

	EXPECT_EQ(*val.first, 1);
	EXPECT_EQ(*val.second, 9);




}
END_TEST()
