#pragma once

// 뉴 카운트 새야함

// 풀링 / 안풀링

// 벡터 ( 리져브 )
// 벡터 ( 노 리져브 )
// 링크드 리스트
// 캐시 링크드 리스트 ( 제작 )

#include <cassert>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

#include <vector>
#include <list>
#include <functional>

#ifdef OUT
	#undef OUT
	#define OUT
#endif

#ifdef IN
	#undef IN
	#define IN
#endif

#pragma region WINDOW_FUNC

enum class CURSOR_TYPE { NOCURSOR, SOLIDCURSOR, NORMALCURSOR };

void SetCursor(const COORD& a_stPos);
void SetCursor(int a_nPosX, int a_nPosY);
void SetCursorType(CURSOR_TYPE c);
void SetConsoleSize(int a_nWidth, int a_nHeight, int a_nX = 20, int a_nY = 20);

void SetCursor(const COORD& a_stPos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a_stPos);
}

void SetCursor(int a_nPosX, int a_nPosY)
{
	SetCursor(COORD{ (short)a_nPosX,(short)a_nPosY });
}

// 커서를 숨기거나 다시 표시한다.
void SetCursorType(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c) {
	case CURSOR_TYPE::NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = false;
		break;
	case CURSOR_TYPE::SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = true;
		break;
	case CURSOR_TYPE::NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = true;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void SetConsoleSize(int a_nWidth, int a_nHeight, int a_nX, int a_nY)
{
	HWND console = GetConsoleWindow();
	MoveWindow(console, a_nX, a_nY, a_nWidth, a_nHeight, TRUE);
}

#pragma endregion


using std::cout;
using std::endl;

#define SAFE_DELETE(x)		{if(x!=nullptr){delete x; x = nullptr;}}
#define SAFE_DELETE_ARR(x)	{if(x!=nullptr){delete[] x; x = nullptr;}}

class Random
{
public:

	enum { size = 1024, max = 10000 };

	static inline int randPool[size] = { 0, };
	static inline int index = 0;

	void static Init()
	{
		srand(time(0));

		for( auto& val : randPool )
		{
			val = rand() % max;
		}
	}

	static int Get()
	{
		int n = index;
		++index;

		index %= index;

		return randPool[n];
	}
};

enum eCaching
{
	Yes,
	No,
};

enum eRenderingType
{
	Buffer,
	Cout,
};

// Render는 define으로 동작을 달리하도록

constexpr int nMakeMaxCountPerFrame = 100;
constexpr int nRunObjectCount = 10000;
constexpr int nTargetFrame = 60;

constexpr int nBoardX = 50;
constexpr int nBoardY = 20;

constexpr float fBulletMaxSpeed = 0.01;
constexpr float fBulletMinSpeed = 0.01;
constexpr float fBulletMaxLife = 3;
constexpr float fBulletMinLife = 2;

using fpRenderFunction = std::function<void(float x, float y, bool bRend)>;
using fpMoveFunction = std::function<void(OUT float& x, OUT float& y, IN float speed)>;

class Bullet
{
public:

	struct ST_BulletData
	{
		float x;
		float y;
		float speed;
		float dirx;
		float diry;
		float life;
	};

	ST_BulletData data;

	bool bRenderBeforeFrame = false;
	fpRenderFunction fpFuncRender;
	fpRenderFunction fpFuncClear;
	fpMoveFunction fpMove;

	using PoolData = ST_BulletData;
	void Init(const PoolData& data,
		fpRenderFunction a_fpRender, fpRenderFunction a_fpClear, fpMoveFunction a_fpMove)
	{
		this->data = data;

		assert(a_fpRender && a_fpClear);

		fpFuncRender = a_fpRender;
		fpFuncClear = a_fpClear;
		// fpMove = a_fpMove;
	}

	bool Update(float delta)
	{
		fpFuncClear(data.x, data.y, bRenderBeforeFrame); // 지우기
		
		// fpMove(data.x, data.y, delta * data.speed);

		data.x += (data.speed * data.dirx);
		data.y += (data.speed * data.diry);

		// true면 화면 바깥. 액티브에서 뺌
		data.life -= delta;
		return data.life < 0;
	}

	void Render()
	{
		bRenderBeforeFrame = !(data.x < 0 || data.x >= nBoardX || data.y < 0 || data.y >= nBoardY);
		fpFuncRender(data.x, data.y, bRenderBeforeFrame);
	}
};

// 테스트 세팅용
constexpr eCaching g_eCache = eCaching::Yes;
constexpr eRenderingType g_eRender = eRenderingType::Buffer;
using PoolTarget = Bullet;
using UsingContainer = std::vector<PoolTarget*>;

template<typename T = PoolTarget,
	typename C = UsingContainer,
	eRenderingType eRender = g_eRender,
	eCaching eCache = g_eCache>
class Board
{
	using itor = typename C::iterator;
	using PoolData = typename T::PoolData;

public:

	~Board() { ClearPool(); }

	void Update(float a_fDelta)
	{
		CreateBullet();

		static std::vector<T*> vcDelete;
		vcDelete.clear();

		for (auto* pObj : m_Bullets)
		{
			if (pObj->Update(a_fDelta) == false)
			{
				vcDelete.push_back(pObj);
			}
		}

		_ReturnPool(OUT vcDelete);
	}

	void Render()
	{
		_Render();
	}

	void ClearPool()
	{
		for (auto* p : m_Bullets)
		{
			SAFE_DELETE(p);
		}

		m_Bullets.clear();

		for (auto* p : m_vcPool)
		{
			SAFE_DELETE(p);
		}

		m_vcPool.clear();
	}

	void Remove(C& from, T* remove)
	{
		itor it = std::find_if(std::begin(from), std::end(from),
			[remove](auto* pObj)
			{
				return pObj == remove;
			});

		if (it != from.end())
		{
			from.erase(it);
		}
	}

	void CreateBullet()
	{
		int n = m_Bullets.size();

		if (n < nRunObjectCount)
		{
			_Make();
		}
	}

	T* MakeBulletInstance()
	{
		T* bullet = new T();
		_InitBullet(OUT *bullet);
		return bullet;		
	}

	// 특수화 할 목록--------------------
	Board();
	void _ReturnPool(OUT std::vector<T*>& vcDelete);
	void _Make();
	void _InitBullet(OUT T& a_cBullet) { assert(false); } // using 바꾸면 저절로 정의 되도록
	void _Render()
	{
		SetCursor(0, 0);
		for (auto* pObj : m_Bullets)
		{
			pObj->Render();
		}
	}

private:
	C m_Bullets;
	std::vector<T*> m_vcPool;
	char** m_pRenderBuffer = nullptr;
};


template<>
Board<PoolTarget, UsingContainer, eRenderingType::Buffer>::
Board()
{
	m_pRenderBuffer = new char*[nBoardY];

	for (int i = 0; i < nBoardY; ++i)
	{
		m_pRenderBuffer[i] = new char[nBoardX + 1];
		memset(m_pRenderBuffer[i], ' ', sizeof(char) * (nBoardX));
		m_pRenderBuffer[i][nBoardX] = 0;
	}
}

template<>
Board<PoolTarget, UsingContainer, eRenderingType::Buffer>::
~Board()
{
	if (m_pRenderBuffer != nullptr)
	{
		for (int i = 0; i < nBoardY; ++i)
		{
			SAFE_DELETE(m_pRenderBuffer[i]);
		}

		SAFE_DELETE(m_pRenderBuffer);
	}

	ClearPool();
}

template<>
void Board<PoolTarget, UsingContainer, eRenderingType::Buffer>::
_Render()
{
	for (auto* pObj : m_Bullets)
	{
		pObj->Render();
	}

	SetCursor(0, 0);
	for (int i = 0; i < nBoardY; ++i)
	{
		cout << m_pRenderBuffer[i] << endl;
	}
}


// using fpRenderFunction = void(*)(float x, float y, bool bRend);
// using fpMoveFunction = void(*)(OUT float& x, OUT float& y, IN float speed);

template<>
void Board<PoolTarget, UsingContainer, eRenderingType::Buffer>::
_InitBullet(OUT PoolTarget& a_cBullet)
{
	int nRand = Random::Get();

	float x = 0;
	float y = 0;
	float dirx = 0;
	float diry = 0;

	float fRate = (float)nRand / Random::max;

	switch (nRand % 4)
	{
		case 0: // 왼쪽 벽
		{
			x = 0;
			y = fRate * nBoardY;

			dirx = fRate;
			diry = fRate - 0.5f;
		}break;
		case 1: // 위 벽
		{
			x = fRate * nBoardX;
			y = 0;

			dirx = fRate - 0.5f;
			diry = fRate;
		}break;
		case 2: // 오른쪽 벽
		{
			x = nBoardX;
			y = fRate * nBoardY;

			dirx = -fRate;
			diry = fRate - 0.5f;
		}break;
		case 3: // 아래벽
		{
			x = fRate * nBoardX;
			y = nBoardY;

			dirx = fRate - 0.5f;
			diry = -fRate;
		}break;
	}

	float speed = fRate * fBulletMaxSpeed + fBulletMinSpeed;
	float life = fRate * fBulletMaxLife + fBulletMinLife;

	static fpRenderFunction fpRender =
	[this](float x, float y, bool bRend)
	{
		if (bRend == true)
		{
			m_pRenderBuffer[(int)y][(int)x] = '@';
		}
	};

	static fpRenderFunction fpClear =
	[this](float x, float y, bool bRend)
	{
		if (bRend == true)
		{
			m_pRenderBuffer[(int)y][(int)x] = ' ';
		}
	};

// 	static fpMoveFunction fpMove[4] 
// 	{
// 		[](OUT float& x, OUT float& y, IN float speed) { x += speed; },
// 		[](OUT float& x, OUT float& y, IN float speed) { y += speed; },
// 		[](OUT float& x, OUT float& y, IN float speed) { x -= speed; },
// 		[](OUT float& x, OUT float& y, IN float speed) { y -= speed; },
// 	};

	a_cBullet.Init(
		{ x, y, speed, dirx, diry, life, },
		fpRender,
		fpClear,
		nullptr
	);
}


template<>
Board<PoolTarget, UsingContainer, eRenderingType::Cout>::
Board() { }

template<>
Board<PoolTarget, UsingContainer, eRenderingType::Cout>::
~Board() { }

template<>
void Board<PoolTarget, UsingContainer, eRenderingType::Cout>::
_InitBullet(OUT PoolTarget& a_cBullet)
{
	int nRand = Random::Get();

	float x = 0;
	float y = 0;
	float dirx = 0;
	float diry = 0;

	float fRate = (float)nRand / Random::max;

	switch (nRand % 4)
	{
	case 0: // 왼쪽 벽
	{
		x = 0;
		y = fRate * nBoardY;

		dirx = fRate;
		diry = fRate - 0.5f;
	}break;
	case 1: // 위 벽
	{
		x = fRate * nBoardX;
		y = 0;

		dirx = fRate - 0.5f;
		diry = fRate;
	}break;
	case 2: // 오른쪽 벽
	{
		x = nBoardX;
		y = fRate * nBoardY;

		dirx = -fRate;
		diry = fRate - 0.5f;
	}break;
	case 3: // 아래벽
	{
		x = fRate * nBoardX;
		y = nBoardY;

		dirx = fRate - 0.5f;
		diry = -fRate;
	}break;
	}

	float speed = ((float)nRand / Random::max * fBulletMaxSpeed) + fBulletMinSpeed;
	float life = (float)nRand / Random::max * fBulletMaxLife + fBulletMinLife;

	static fpRenderFunction fpRender =
		[this](float x, float y, bool bRend)
	{
		if (bRend == true)
		{
			SetCursor(x, y);
			cout << "@";
		}
	};

	static fpRenderFunction fpClear =
		[this](float x, float y, bool bRend)
	{
		if (bRend == true)
		{
			SetCursor(x, y);
			cout << " ";
		}
	};

// 	static fpMoveFunction fpMove[4]
// 	{
// 		[](OUT float& x, OUT float& y, IN float speed) { x += speed; },
// 		[](OUT float& x, OUT float& y, IN float speed) { y += speed; },
// 		[](OUT float& x, OUT float& y, IN float speed) { x -= speed; },
// 		[](OUT float& x, OUT float& y, IN float speed) { y -= speed; },
// 	};

	a_cBullet.Init(
		{ x, y, speed, dirx, diry, life, },
		fpRender,
		fpClear,
		nullptr
	);
}

template<>
void Board<PoolTarget, UsingContainer, g_eRender, eCaching::Yes>::
_ReturnPool(OUT std::vector<PoolTarget*>& vcDelete)
{
	for (auto* pObj : vcDelete)
	{
		Remove(m_Bullets, pObj);
		m_vcPool.push_back(pObj);
	}

	vcDelete.clear();
}

template<>
void Board<PoolTarget, UsingContainer, g_eRender, eCaching::Yes>::
_Make()
{
	for (int i = 0; i < nMakeMaxCountPerFrame; ++i)
	{
		decltype(MakeBulletInstance()) pBullet = nullptr;

		if (m_vcPool.size() > 0)
		{
			pBullet = m_vcPool.back();
			m_vcPool.pop_back();
		}
		else
		{
			pBullet = MakeBulletInstance();
		}

		m_Bullets.push_back(pBullet);
	}
}

template<>
void Board<PoolTarget, UsingContainer, g_eRender, eCaching::No>::
_ReturnPool(OUT std::vector<PoolTarget*>& vcDelete)
{
	for (auto* pObj : vcDelete)
	{
		Remove(m_Bullets, pObj);
		SAFE_DELETE(pObj);
	}

	vcDelete.clear();
}

template<>
void Board<PoolTarget, UsingContainer, g_eRender, eCaching::No>::
_Make()
{
	for (int i = 0; i < nMakeMaxCountPerFrame; ++i)
	{
		auto* pBullet = MakeBulletInstance();
		m_Bullets.push_back(pBullet);
	}
}

class App
{
	constexpr float GetTargetFPS()
	{
		return (1 / nTargetFrame) * 1000;
	}

public:

	App()
	{
		pBoard = std::make_unique<Board<>>();

		Random::Init();
		SetConsoleSize(800, 600);
		SetCursorType(CURSOR_TYPE::NOCURSOR);
	}

	void Run()
	{
		system("cls");
		clock_t programStart = clock();

		while (true)
		{
			clock_t now = clock();
			clock_t term = now - m_nLastStamp;

			if (term > GetTargetFPS())
			{
				m_nDeltaTick = term;
				m_nLastStamp = now;

				float fDeltaTime = m_nDeltaTick / (float)1000;

				if (Update(fDeltaTime) == false) { break; }

				Render();

				m_nTotalLoop += (clock() - now);
			}
		}

		m_nProgramEnd = clock() - programStart;

		system("cls");

		cout << "프로그램 총 실행 시간 : " << m_nProgramEnd << endl;
		cout << "루프 : " << m_nTotalLoop << endl;
	}

private:
	bool Update(float a_fDelta)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			return false;
		}

		pBoard->Update(a_fDelta);

		return true;
	}

	void Render()
	{
		pBoard->Render();
	}


	clock_t m_nDeltaTick;
	clock_t m_nLastStamp = 0;

	clock_t m_nProgramEnd = 0;
	clock_t m_nTotalLoop= 0;

	std::unique_ptr<Board<>> pBoard;
};
