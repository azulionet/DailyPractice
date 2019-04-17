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


struct WeaponData
{
	int nID;
	int nData;

	static const char* GetTableName() { return "Weapon"; }
};

struct ArmorData
{
	int nID;
	int nData;

	static const char* GetTableName() { return "Armor"; }
};


template<typename T>
class Table
{
	static Table* m_pInstance;

public:

	static Table* GetInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new Table<T>();
		}

		return m_pInstance;
	}

	T* GetTable(int a_nID)
	{
		std::cout << T::GetTableName() << std::endl;

		auto itor = m_mapTb.find(a_nID);
		if (itor != std::end(m_mapTb))
		{
			return &(*itor).second;
		}

		return nullptr;
	}
private:
	std::map<int, T> m_mapTb;
};


template<>
Table<WeaponData>* Table<WeaponData>::m_pInstance = nullptr;

template<>
Table<ArmorData>* Table<ArmorData>::m_pInstance = nullptr;

#define GetWeaponTb(n) ( Table<WeaponData>::GetInstance()->GetTable((n)) )
#define GetArmorTb(n) ( Table<ArmorData>::GetInstance()->GetTable((n)) )

inline void RemoveFlag(uint32 a_nOrder, REF uint32& a_nRefNum) // a_nOrder = 0~31
{
	a_nRefNum &= (~(1 << a_nOrder));
}




class Printable
{
public:
	int GetValue() const
	{
		return 10;
	}
};


class Printable2
{
public:
	int GetValue() const
	{
		return 2;
	}
};

class Printable3
{
public:
	int GetValue() const
	{
		return 3;
	}
};

using namespace std;

template<typename T>
ostream& operator<<(ostream& o, const T& p)
{
	o << p.GetValue();
	return o;
}

END_PRACTICE
