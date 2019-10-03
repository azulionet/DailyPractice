#include "pch.h"
#include "Day0029.h"
#include <iostream>

using std::cout;
using std::endl;


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
				BT::Sequence()->Add(
				{
					BT::Condition(std::bind(&Day0029::IsNotInDetectRange, this)),
					BT::Action(std::bind(&Day0029::DoIdle, this)),
				}),
				BT::Sequence()->Add(
				{
					BT::Switch(BT::Condition(std::bind(&Day0029::MoveToCanAttackArea, this))),
					BT::Action(std::bind(&Day0029::DoAttack, this)),
				}),
			}),
		}
	);
}

void Day0029::Tick()
{
	m_pBTRoot->Tick();
}

bool Day0029::IsNotInDetectRange()
{
	return true; // 대충 내 감지거리 안인지`
}

void Day0029::DoIdle()
{
	cout << "Idle" << endl;
}

// Move가 속도만큼 최대거리를 이동하지 않았다면 false리턴
bool Day0029::MoveToCanAttackArea()
{
	// 이동할만큼 이동했다.
	return true;

	// 쬐금 이동 ( 사정거리안에 플레이어가 있어서 ) 
	return false;
}

void Day0029::DoAttack()
{
	cout << "Attack" << endl;
}
