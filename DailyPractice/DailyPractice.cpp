// DailyPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

#include <vld.h>

// #include "Practice/Day0001.h"
// #include "Practice/Day0002.h"
#include "Practice/Day0005.h"

using namespace std;

USING_PRACTICE

template<int N>
class A
{
public:
	constexpr A()
	{
		std::cout << N << "\n";
	}
};

// static constexpr auto table = gen_table();

int main()
{

	BinaryTree<int> tree;

	tree.AddListLevelOrder({1,2,3,4,5,6,7,8,9,10});
	tree.AddListLevelOrder({11, 12, 13, 14, 15, 16, 17, 18, 19, 20});

	tree.TreeTraversal_LevelOrder(tree.m_pRoot);

	
	getchar();
	return 0;
}
