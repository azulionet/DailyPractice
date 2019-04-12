#pragma once

#include "DailyPractice/Define.h"

BEGIN_PRACTICE

#pragma region __TB__

struct Weapon
{
	int		nID;
	char	sName[32];
	char	sInfo[32];

	int		nHealth;
	int		nPow;
	int		nAgi;
	int		nInt;
};

class WeaponTable
{
public:

	void Init()
	{
		int nFileContentCount = 10; // ���Ͽ��� �д´ٰų�, �������� �޾ƿԴ� ġ��...

		map.insert({ 1,		Weapon{1, "���ҵ�", "���ҵ���", 1,1,1,1} });
		map.insert({ 2,		Weapon{2, "�ռҵ�", "�ռҵ���", 2,2,2,2} });
		map.insert({ 3,		Weapon{3, "�շռҵ�", "�շռҵ���", 3,3,3,3} });
		map.insert({ 4,		Weapon{4, "�÷Լҵ�", "�÷Լҵ���", 4,4,4,4} });
		map.insert({ 5,		Weapon{5, "����ҵ�", "����ҵ���", 5,5,5,5} });

		map.insert({ 101,	Weapon{101, "â", "â��", 6,6,6,6} });
		map.insert({ 102,	Weapon{102, "����", "������", 11,11,11,11} });
		map.insert({ 103,	Weapon{103, "Ȱ", "Ȱ��", 12,12,12,12} });
		map.insert({ 104,	Weapon{104, "����", "������", 13,13,13,13} });
		map.insert({ 105,	Weapon{105, "��", "����", 14,14,14,14} });
	}

	const Weapon* GetTb(int a_nID)
	{
		if (map.find(a_nID) == map.end())
		{
			std::string s = "not find id : ";
			s += std::to_string(a_nID);

			assert(false && s.c_str());
			return nullptr;
		}

		return &map[a_nID];
	}

private:
	std::map<int, Weapon> map;
};

#pragma endregion

enum { SIMPLE_CONTAINER_COUNT = 5, };

// simple
class SimpleStack
{
public:
	void Push(int n)	{ ar[nTop++] = n; }
	void Pop()			{ --nTop; }
	int Peek() const	{ return ar[nTop]; }
	int Size() const	{ return nTop;}
	int GetBufferSize() const { return SIMPLE_CONTAINER_COUNT; }

private:
	int ar[SIMPLE_CONTAINER_COUNT];
	int nTop = 0;
};

class SimpleQueue
{
public:
	void Push(int n)	{ ar[nRear++] = n; nRear %= (SIMPLE_CONTAINER_COUNT+1); }
	void Pop()			{ ++nFront; nFront %= (SIMPLE_CONTAINER_COUNT+1); }
	int Peek() const	{ return ar[nFront]; }

	int Size() const
	{
		if (nFront == nRear) { return 0; }

// 		if (nRear > nFront)
// 		{
// 			return nRear - nFront;
// 		}
// 		else
// 		{
// 			return MAX + nRear - nFront;
// 		}

		return (MAX + nRear - nFront) % MAX;		
	}

	const int MAX = GetBufferSize() + 1;
	int GetBufferSize() const { return SIMPLE_CONTAINER_COUNT; }

private:
	int nFront = 0;
	int nRear = 0;

	int ar[SIMPLE_CONTAINER_COUNT + 1];
};





END_PRACTICE
