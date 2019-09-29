#include "pch.h"
#include "Day0029.h"


Day0029::Day0029()
	: m_pBTRoot(BT::Root())
{}

Day0029::~Day0029()
{
	delete m_pBTRoot;
}

void Day0029::CreateNode()
{
	m_pBTRoot->Add(
		{
			BT::Selector()->Add(
			{
// 				BT::Sequence()->Add(
// 				{
// 					BT::Condition(사거리밖?),
// 					BT::Action(아이들)
// 				}),
// 				BT::Sequence()->Add(
// 				{
// 					BT::Switch(BT::Condition(MoveToCanAttackArea), // Move가 속도만큼 최대거리를 이동하지 않았다면 false리턴
// 					BT::Action(공격),
// 				}),
			}),
		}
	);
}

void Day0029::Tick()
{

}

