#pragma once

#include "Components.h"


namespace Game
{
	class PlayerComponent : public Component
	{
	private:
		TransformComponent* transform;

	public:

		PlayerComponent();

		void init() override;

		void update() override;

	};
}
