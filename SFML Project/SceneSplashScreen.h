#ifndef SCENESPLASHSCREEN_H
#define SCENESPLASHSCREEN_H
#pragma once

#include "SceneStateMachine.h"

namespace Game
{
	class SceneSplashScreen : public SceneState
	{
	public:
		SceneSplashScreen(SceneStateMachine sceneStateMachine, Window* window);

		void OnCreate() override;
		void OnDestroy() override;

		void OnActivate() override;

		void SetSwitchToScene(unsigned int id);

		void Update(float deltaTime) override;
		void Draw(Window* window) override;

	private:
		sf::Texture splashTexture;
		sf::Sprite splashSprite;

		SceneStateMachine& sceneStateMachine;
		Window* window;

		// We want to show this scene for a set amount of time
		float showForSeconds;

		// How long the scene has currently been visible.
		float currentSeconds;

		// The state we want to transition to when this scenes time expires.
		unsigned int switchToState;
	};
}


#endif /* SCENESPLASHSCREEN_H */

