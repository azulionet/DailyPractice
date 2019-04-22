#include "../../pch.h"
#include "IntroScene.h"
#include <cassert>

namespace W
{
	IntroScene::IntroScene(SceneManager * a_pParent) : Scene{ a_pParent } { }
	IntroScene::~IntroScene() { }
	SceneManager::eScene IntroScene::GetScene() { return SceneManager::eScene::Intro; }

	void IntroScene::Init() { }
	void IntroScene::Update() { }
	void IntroScene::Render() { }
	void IntroScene::KeyInput(SceneManager::eKey a_eKey) { }
}

