#include "pch.h"

#include "Practice/Day0011.h"


USING_PRACTICE

#include <cassert>


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

int main()
{
	using namespace std;

	GetWeaponTb(1);
	GetArmorTb(1);
	


	getchar();
}