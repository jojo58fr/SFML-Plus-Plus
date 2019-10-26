#include "PlayerComponent.h"

namespace Game
{
	PlayerComponent::PlayerComponent()
	{
		this->transform = new TransformComponent();
	}

	void PlayerComponent::init()
	{
		this->transform = &entity->getComponent<TransformComponent>();
	}

	void PlayerComponent::update()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) transform->position.y--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) transform->position.y++;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) transform->position.x--;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) transform->position.x++;
	}
}
