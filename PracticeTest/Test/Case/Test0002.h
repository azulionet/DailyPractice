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

	for (int i = -2; i < 13; ++i)
	{
		EXPECT_EQ(li.Find(i), li.RFind(i));
		EXPECT_EQ(li.Get(i), li.RGet(10 - i - 1));
	}

	for (int i = 0; i < 5; ++i)
	{		
		EXPECT_EQ(li.Get(i)->val + li.RGet(i)->val, 9);
	}

	li.Clear();

	EXPECT_EQ(li.Count(), 0);

	


}
END_TEST()