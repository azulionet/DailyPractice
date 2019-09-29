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

	bool IsInDetectRange()
	{
		return true; // 대충 내 감지거리 안인지`
	}

	
};
