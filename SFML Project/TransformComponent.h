#pragma once
#include "Components.h"
#include "Vector2D.h"

using namespace Game;

namespace ECS
{
	class TransformComponent : public Component
	{

	private:


	public:

		Vector2D position;

		TransformComponent()
		{
			position.x = 0.0f;
			position.y = 0.0f;
		}

		TransformComponent(float x, float y)
		{
			position.x = x;
			position.y = y;
		}

		float x() { return position.x; }
		float y() { return position.y; }

		void init() override
		{
			position.x = 0;
			position.y = 0;
		}

		void update() override
		{
			//position.x++;
			//position.y++;

		}

		void setPosition(float x, float y)
		{
			position.x = x;
			position.y = y;
		}

	};

}
