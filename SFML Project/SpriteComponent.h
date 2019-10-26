#pragma once
#include <SFML\Graphics.hpp>

#include "Components.h"
#include "DrawManagement.h"

using namespace std;

namespace ECS
{
	class SpriteComponent : public Component
	{
	private:
		TransformComponent* position;

		sf::Texture texture;
		sf::Sprite sprite;

		sf::RectangleShape shape;
	public:
		SpriteComponent() = default;

		SpriteComponent(const char* path)
		{

			//Load Texture Image
			if (!texture.loadFromFile(path))
			{
				throw (exception("Unable to open file"));
				//this->sprite->setTextureRect(sf::IntRect(10, 10, 32, 32));
			}

			sprite.setTexture(texture);

			//cout << entity->hasComponent() << endl;

		}

		void init() override
		{
			this->position = &entity->getComponent<TransformComponent>();

		}

		void update() override
		{
			sprite.setPosition(sf::Vector2f(position->x(), position->y()));
		}

		void render() override
		{
			DrawManagement::getInstance()->draw(this->sprite);
		}

		void setSprite(const char* path)
		{
			if (!texture.loadFromFile(path))
			{
				throw (exception("Unable to open file"));
			}

			sprite.setTexture(texture);
		}
	};

}
