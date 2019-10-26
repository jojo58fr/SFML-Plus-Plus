#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

namespace Game
{
	class DrawManagement
	{
	private:
		static DrawManagement* instance;
		DrawManagement();

		sf::RenderWindow* window;
	public:
		static DrawManagement* getInstance();

		void setWindow(sf::RenderWindow* window);
		sf::RenderWindow* getWindow();

		void draw(const sf::Drawable& drawObject);
	};
}

