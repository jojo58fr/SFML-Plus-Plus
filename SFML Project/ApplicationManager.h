#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#pragma once

#include <string>

#include "GameObject.h"
#include "DrawManagement.h"
#include "Window.h"
#include "InputSystem.h"
#include "SceneStateMachine.h"
#include "Components.h"
#include "SceneSplashScreen.h"

using namespace std;

namespace Game 
{
	class ApplicationManager
	{

	public:
		ApplicationManager();
		~ApplicationManager();

		void Update();
		void LateUpdate();

		void Draw();
		
		const bool IsRunning() const;

		void CalculateDeltaTime();
		void CaptureInput();
	private:
		Window* window;

		sf::Clock clock;
		float deltaTime;

		InputSystem input;

		SceneStateMachine sceneStateMachine;
	};

}

#endif /* DISPLAYMANAGER_H */

