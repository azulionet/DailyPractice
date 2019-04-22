#include "../../pch.h"
#include "GameScene.h"

#include <cassert>

namespace W
{
	GameScene::GameScene(SceneManager * a_pParent) : Scene {a_pParent} { }
	GameScene::~GameScene() { }

	SceneManager::eScene GameScene::GetScene() { return SceneManager::eScene::Game;  }

	void GameScene::Init() { }
	void GameScene::Update() { }
	void GameScene::Render() { }
	void GameScene::KeyInput(SceneManager::eKey a_eKey) { }
}

