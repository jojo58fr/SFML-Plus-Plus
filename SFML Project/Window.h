#ifndef WINDOW_H
#define WINDOW_H
#pragma once

#include <SFML/Graphics.hpp>

namespace Game
{
	class Window
	{
	public:
		Window(const std::string& windowName, int windowWidth = 800, int windowHeight = 600);
		~Window();

		void Update();

		void BeginDraw();
		void Draw(const sf::Drawable& drawable);
		void EndDraw();

		sf::Vector2u GetCenter() const;
		sf::Vector2f GetSize() const;
		sf::View GetView() const;

		bool IsOpen() const;

	private:
		sf::VideoMode videoMode;
		sf::RenderWindow* window;

	};
}

#endif /* WINDOW_H */

