#ifndef PLAYERCOMPONENT_H
#define PLAYERCOMPONENT_H
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

#endif /* PLAYERCOMPONENT_H */
