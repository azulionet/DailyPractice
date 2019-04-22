#include "../../pch.h"
#include "Define.h"

#include "SceneManager.h"
#include "Scene.h"

#include "IntroScene.h"
#include "GameScene.h"

using namespace W;

SceneManager * SceneManager::CreateInstance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new SceneManager();
	}
}

SceneManager * SceneManager::GetInstance()
{
	return m_pInstance;
}

void SceneManager::ReleaseInstance()
{
	SAFE_DELETE(m_pInstance);
}



SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	SAFE_DELETE(m_pNowScene);
}

void SceneManager::Init()
{
	ChangeScene(eScene::Intro);
}

void SceneManager::ChangeScene(eScene a_eScene)
{
	SAFE_DELETE(m_pNowScene);

	switch(a_eScene)
	{
		case eScene::Intro:
		{
			m_pNowScene = new IntroScene(this);
		} break;
		case eScene::Game
		{
			m_pNowScene = new GameScene(this);
		} break;
	}

	m_pNowScene->Init();
}

void SceneManager::Update()
{
	m_pNowScene->Update();
}

void SceneManager::Render()
{
	m_pNowScene->Render();
}

void SceneManager::KeyInput(eKey a_eKey)
{
	m_pNowScene->KeyInput(a_eKey);
}

