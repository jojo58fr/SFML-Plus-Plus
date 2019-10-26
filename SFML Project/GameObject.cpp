#include "GameObject.h"

namespace Game
{
	GameObject::GameObject(string nameObject)
	{
		xpos = 0;
		ypos = 0;

		this->shape.setFillColor(sf::Color::Green);

		sf::Vector2f size(50.f, 50.f);
		this->shape.setSize(size);
	}

	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{

	}

	void GameObject::Render(sf::RenderTarget* target)
	{
		target->draw(this->shape);
	}
}
