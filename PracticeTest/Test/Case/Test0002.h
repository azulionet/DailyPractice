#pragma once

#include "DailyPractice/Practice/Day0002.h"

USING_PRACTICE

BEGIN_TEST(Day, 2)
{
	LinkedList<int> li;

	for (int i = 0; i < 10; ++i)
	{
		li.Add(i);
	}

	EXPECT_EQ(li.Count(), 10);

	li.Clear();

	EXPECT_EQ(li.Count(), 0);


}
END_TEST()