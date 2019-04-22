#pragma once

class SceneManager
{
public:

	enum class eKey
	{
		Left,
		Up,
		Right,
		Down,

	};

	enum class eScene
	{
		None,

		Intro,
		Game,
	};

#pragma region SINGLETON

private:
	static inline SceneManager * m_pInstance = nullptr;
	SceneManager();
	~SceneManager();
	
	SceneManager operator=(SceneManager&) = delete;	
	SceneManager(SceneManager&&) = delete;
	SceneManager(const SceneManager&) = delete;

public:

	static SceneManager * CreateInstance();
	static inline SceneManager * GetInstance();
	static void ReleaseInstance();

#pragma  endregion SINGLETON

public:

	~SceneManager();
	
	void Init();
	void ChangeScene(eScene a_eScene);

	void Update();
	void Render();

	void KeyInput(eKey a_eKey);

public:

	class Scene * m_pNowScene = nullptr;
};


#define InitSceneMng()		{SceneManager::GetInstance()->Init();}
#define SceneMng()			(SceneManager::GetInstance())
#define ReleaseSceneMng()	(SceneManager::ReleaseInstance())