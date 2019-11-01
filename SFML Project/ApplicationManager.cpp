#include "ApplicationManager.h"

//TODO Corriger création personnage (MAJ avec Scene Management)
namespace Game 
{

	Manager* ECSManager = new Manager();

	//GameObject* player = new GameObject("Player");
	auto& newPlayer(ECSManager->addEntity());

	ApplicationManager::ApplicationManager()
	{
		window = new Window("SFML Project");

		std::shared_ptr<SceneSplashScreen> splashScreen =
			std::make_shared<SceneSplashScreen>(sceneStateMachine,
				window);

		unsigned int splashScreenID = sceneStateMachine.Add(splashScreen);

		//splashScreen->SetSwitchToScene(0); //3

		sceneStateMachine.SwitchTo(splashScreenID); //4


		deltaTime = clock.restart().asSeconds();

		//newPlayer.addComponent<TransformComponent>();
		//newPlayer.addComponent<SpriteComponent>("assets/player.png");
	}

	ApplicationManager::~ApplicationManager()
	{

	}

	void ApplicationManager::Update()
	{
		window->Update();

		sceneStateMachine.Update(deltaTime);

		ECSManager->update();
		//Render Update
		/*std::cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
			newPlayer.getComponent<PositionComponent>().y() << std::endl;*/
	}

	void ApplicationManager::LateUpdate()
	{
		sceneStateMachine.LateUpdate(deltaTime);
	}

	void ApplicationManager::Draw()
	{
		/*
		 @return void

		 - Clear old frame
		 - Render Object
		 Render the game objects
		*/

		window->BeginDraw();

		sceneStateMachine.Draw(window);

		//Render Display
		//this->object->Render(this->window);
		ECSManager->draw();

		window->EndDraw();
	}

	const bool ApplicationManager::IsRunning() const
	{
		return window->IsOpen();
	}

	void ApplicationManager::CalculateDeltaTime()
	{
		deltaTime = clock.restart().asSeconds();
	}
	void ApplicationManager::CaptureInput()
	{
		input.Update();
	}
}
