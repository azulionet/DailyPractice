// DailyPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"


#include "Practice/Day0001.h"
#include "Practice/Day0002.h"

using namespace std;

USING_PRACTICE

void main()
{
	LinkedList<int> li;

	for (int i = 0; i < 10; ++i)
	{
		li.Add(i);
	}

	cout << li.Count() << endl;

	getchar();
}
