#include "DrawManagement.h"

namespace Game
{
	/* Singleton Pattern */

	/* Null, because instance will be initialized on demand. */
	DrawManagement* DrawManagement::instance = 0;

	DrawManagement::DrawManagement()
	{
		this->window = new sf::RenderWindow();
	}

	DrawManagement* DrawManagement::getInstance()
	{
		if (instance == 0)
		{
			instance = new DrawManagement();
		}

		return instance;
	}

	/* End Singleton Pattern */

	void DrawManagement::setWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}

	sf::RenderWindow* DrawManagement::getWindow()
	{
		return this->window;
	}

	void DrawManagement::draw(const sf::Drawable& drawObject)
	{
		this->window->draw(drawObject);
	}

}
