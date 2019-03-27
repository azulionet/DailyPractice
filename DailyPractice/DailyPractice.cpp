// DailyPractice.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"


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

	tree.AddValue(5);
	tree.AddValue(3);
	tree.AddValue(8);
	tree.AddValue(2);
	tree.AddValue(4);

	tree.AddValue(1);
	tree.AddValue(7);
	tree.AddValue(9);
	tree.AddValue(6);
	tree.AddValue(10);

	tree.Stack_TreeTraversal_InOrder(tree.m_pRoot);
	getchar();
	return 0;
}
