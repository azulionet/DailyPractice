#pragma once

#include "BT.h"
#include <memory>

class Day0029
{
public:
	Day0029();
	~Day0029();

	void CreateNode();
	void Tick();

	BT_NODE::BTRoot* const m_pBTRoot;

	// BT 동작들
	bool IsNotInDetectRange();
	void DoIdle();
	bool MoveToCanAttackArea();
	void DoAttack();
};
