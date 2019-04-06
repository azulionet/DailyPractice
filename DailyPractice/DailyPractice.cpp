// DailyPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

#include <vld.h>
#include "Practice/Day0007.h"


using namespace std;

USING_PRACTICE

#include <cstdlib>
#include <ctime>

#pragma comment(lib, "winmm.lib")
#include <windows.h>

constexpr int Fibo(int n)
{
	if (n <= 1) { return n; }
	return Fibo(n - 2) + Fibo(n - 1);
}

constexpr int Fibo2(int n)
{
	if (n <= 1) { return n; }

	int n0 = 0;
	int n1 = 1;

	for (int i = 1; i < n; ++i)
	{
		(i%2 == 0) ? n1 += n0 : n0 += n1;
	}

	return n0 > n1 ? n0 : n1;
}

int main()
{
	float fTimeStamp = timeGetTime();

	cout << Fibo(25) << endl;
	cout << timeGetTime() - fTimeStamp << endl;

	int n = 25;
	fTimeStamp = timeGetTime();

	cout << Fibo(n) << endl;
	cout << timeGetTime() - fTimeStamp << endl;




	fTimeStamp = timeGetTime();

	for (int i = 0; i < 20; ++i)
	{
		cout << Fibo2(50) << endl;
	}
	
	cout << timeGetTime() - fTimeStamp << endl;


	int n50 = 50;

	fTimeStamp = timeGetTime();

	for (int i = 0; i < 20; ++i)
	{
		cout << Fibo2(n50) << endl;
	}
	
	cout << timeGetTime() - fTimeStamp << endl;







	getchar();
	return 0;
}
