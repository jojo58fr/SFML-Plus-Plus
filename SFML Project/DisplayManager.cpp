#include "DisplayManager.h"
#include "Components.h"
//TODO Corriger création personnage (MAJ avec Scene Management)
namespace Game 
{

	Manager* ECSManager = new Manager();

	//GameObject* player = new GameObject("Player");
	auto& newPlayer(ECSManager->addEntity());

	DisplayManager::DisplayManager()
	{
		DisplayManager::SetupWindow(800, 600, "SFML Project");

		newPlayer.addComponent<TransformComponent>();
		newPlayer.addComponent<SpriteComponent>("assets/player.png");
	}

	DisplayManager::~DisplayManager()
	{
		this->window->close();
	}


	void DisplayManager::SetupWindow(int windowsWidth, int windowHeight, string windowTitle)
	{
		this->videoMode.width = windowsWidth;
		this->videoMode.height = windowHeight;

		this->window = new sf::RenderWindow(videoMode, windowTitle);
		this->window->setFramerateLimit(120);
		this->window->setVerticalSyncEnabled(false);

		DrawManagement::getInstance()->setWindow(window);
	}


	const bool DisplayManager::IsRunning() const
	{
		return this->window->isOpen();
	}

	void DisplayManager::handleWindowInput()
	{
		// while there are pending events...
		while (this->window->pollEvent(this->sfmlEvent))
		{
			// check the type of the event...
			switch (this->sfmlEvent.type)
			{
				// window closed
			case sf::Event::Closed:
				this->window->close();
				break;

				// key pressed
			case sf::Event::KeyPressed:
					break;

			default:
				break;
			}
		}
	}

	void DisplayManager::update()
	{
		this->handleWindowInput();

		ECSManager->update();
		//Render Update
		/*std::cout << newPlayer.getComponent<PositionComponent>().x() << "," <<
			newPlayer.getComponent<PositionComponent>().y() << std::endl;*/
	}

	void DisplayManager::render()
	{
		/*
		 @return void

		 - Clear old frame
		 - Render Object
		 Render the game objects
		*/

		this->window->clear();

		//Render Display
		//this->object->Render(this->window);
		DrawManagement::getInstance()->setWindow(this->window);
		ECSManager->draw();

		this->window->display();
	}

}
