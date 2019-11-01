#include "Window.h"

namespace Game
{
	Window::Window(const std::string& windowName, int windowWidth, int windowHeight)
	{
		videoMode.width = windowWidth;
		videoMode.height = windowHeight;

		window = new sf::RenderWindow(videoMode, windowName);
		window->setFramerateLimit(120);
		window->setVerticalSyncEnabled(false);
	}

	Window::~Window()
	{
		window->close();
	}

	void Window::Update()
	{
		sf::Event sfmlEvent;

		// while there are pending events...
		while (window->pollEvent(sfmlEvent))
		{
			// check the type of the event...
			switch (sfmlEvent.type)
			{

				// window closed
			case sf::Event::Closed:
				this->window->close();
				break;

			default:
				break;
			}
		}
	}

	void Window::BeginDraw()
	{
		window->clear();
	}

	void Window::Draw(const sf::Drawable& drawable)
	{
		window->draw(drawable);
	}

	void Window::EndDraw()
	{
		window->display();
	}

	sf::Vector2u Window::GetCenter() const
	{
		sf::Vector2u size = window->getSize();

		return sf::Vector2u(size.x / 2, size.y / 2);
	}

	sf::Vector2f Window::GetSize() const
	{
		return window->getView().getSize();
	}

	sf::View Window::GetView() const
	{
		return window->getView();
	}

	bool Window::IsOpen() const
	{
		return window->isOpen();
	}
}