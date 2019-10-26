#pragma once
#include <SFML/Window.hpp>
#include <SFML\Graphics.hpp>

#include <string>
#include "GameObject.h"
#include "DrawManagement.h"

using namespace std;

namespace Game 
{
	class DisplayManager
	{

	public:
		DisplayManager();
		~DisplayManager();

		const bool IsRunning() const;
		void handleWindowInput();

		void update();
		void render();


	private:
		sf::VideoMode videoMode;
		sf::RenderWindow* window;
		sf::Event sfmlEvent;
		DrawManagement* drawManagement;

		GameObject* object = new GameObject("Gameobject");


		bool endApplication;

		void SetupWindow(int windowsWidth, int windowHeight, string windowTitle);
	};

}

