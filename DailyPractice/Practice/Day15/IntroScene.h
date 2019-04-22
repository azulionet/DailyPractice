#pragma once

#include "Scene.h"
#include "SceneManager.h"

namespace W
{
	class IntroScene : public Scene
	{
	public:

		IntroScene(SceneManager * a_pParent);
		virtual ~IntroScene();

		virtual SceneManager::eScene GetScene();

		virtual void Init();
		virtual void Update();
		virtual void Render();
		virtual void KeyInput(SceneManager::eKey a_eKey);

	public:

		class SceneManager * m_refParent = nullptr;
	};
}
