#pragma once

#include "DailyPractice/Practice/Day0002.h"

USING_PRACTICE

BEGIN_TEST(Day, 2)
{
	LinkedList<int> li;
	const int nMakeCount = 60;

	for (int i = 0; i < nMakeCount; ++i)
	{
		li.Add(i);
		EXPECT_EQ(li.Count(), i+1);
	}

	EXPECT_EQ(li.Count(), nMakeCount);

	for (int i = -2; i < nMakeCount+5; ++i)
	{
		EXPECT_EQ(li.Find(i), li.RFind(i));
		EXPECT_EQ(li.Get(i), li.RGet(nMakeCount - i - 1));
	}

	for (int i = 0; i < nMakeCount/2; ++i)
	{		
		EXPECT_EQ(li.Get(i)->val + li.RGet(i)->val, nMakeCount-1);
	}

	li.Clear();

	EXPECT_EQ(li.Count(), 0);

	


}
END_TEST()