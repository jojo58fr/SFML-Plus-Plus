#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

using namespace std;

namespace Game
{
	class GameObject
	{
	public:
		GameObject(string nameObject);
		~GameObject();

		void Update();
		void Render(sf::RenderTarget* target);
	private:

		int xpos;
		int ypos;

		sf::RectangleShape shape;

	};
}

#endif /* GAMEOBJECT_H */

