#pragma once

#include "DailyPractice/Practice/Day0001.h"

USING_PRACTICE

BEGIN_TEST(Day, 1)
{
	EXPECT_EQ(EuclidMod_NoStd(250, 30), 10);
	EXPECT_EQ(EuclidMod_NoStd(30, 250), 10);

	EXPECT_EQ(EuclidMod_NoStd(25, 30) , 5);
	EXPECT_EQ(EuclidMod_NoStd(30, 25) , 5);
	
	EXPECT_EQ(EuclidMod_NoStd(300, 300), 300);

	EXPECT_EQ(EuclidMod_NoStd(0, 0) , 0);
	EXPECT_EQ(EuclidMod_NoStd(1, 0) , 0);
	EXPECT_EQ(EuclidMod_NoStd(0, 1) , 0);
}
END_TEST()