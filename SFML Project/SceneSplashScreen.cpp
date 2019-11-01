#include "SceneSplashScreen.h"
#include <iostream>

namespace Game {

	SceneSplashScreen::SceneSplashScreen(SceneStateMachine sceneStateMachine, Window* window) : sceneStateMachine(sceneStateMachine)
	{
		this->window = window;
		switchToState = 0;
		currentSeconds = 0.f;
		showForSeconds = 4.f;
	}

	void SceneSplashScreen::OnCreate()
	{
		splashTexture.loadFromFile("assets/splashscreen.png");
		splashSprite.setTexture(splashTexture);

		sf::FloatRect spriteSize = splashSprite.getLocalBounds();
		splashSprite.setOrigin( spriteSize.width * 0.5f,
								spriteSize.height * 0.5f);

		//Resize Splashscreen by screen size
		sf::Vector2f targetSize = window->GetSize();
		splashSprite.setScale(
			targetSize.x / splashSprite.getLocalBounds().width,
			targetSize.y / splashSprite.getLocalBounds().height);

		sf::Vector2u windowCentre = window->GetCenter();
		// Positions sprite in centre of screen:
		splashSprite.setPosition((float) windowCentre.x, (float) windowCentre.y);
		
		//std::cout << "Coucou console c++ !" << endl;

	}

	void SceneSplashScreen::OnDestroy()
	{

	}

	void SceneSplashScreen::OnActivate()
	{
		// Resets the currentSeconds count whenever the scene is activated.
		currentSeconds = 0.f;
	}

	void SceneSplashScreen::SetSwitchToScene(unsigned int id)
	{
		// Stores the id of the scene that we will transition to.
		switchToState = id;
	}

	void SceneSplashScreen::Update(float deltaTime)
	{
		currentSeconds += deltaTime;

		if (currentSeconds >= showForSeconds)
		{
			// Switches states.
			//sceneStateMachine.SwitchTo(switchToState);
		}
	}

	void SceneSplashScreen::Draw(Window* window)
	{
		window->Draw(splashSprite);
		//cout << "Test C++" << endl;
	}

}