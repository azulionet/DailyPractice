#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

#include <iomanip>


using uint8 = unsigned char;
using uing16 = unsigned short;
using uint32 = unsigned int;

enum { eBit = 8, };

#define IN
#define OUT
#define REF



inline void RemoveFlag(uint32 a_nOrder, REF uint32& a_nRefNum) // a_nOrder = 0~31
{
	a_nRefNum &= (~(1 << a_nOrder));
}

END_PRACTICE
