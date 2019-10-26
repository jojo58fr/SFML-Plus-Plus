#pragma once
#include <vector>

#include "ECS.h";

namespace ECS
{
	class Manager
	{
	private:
		std::vector<std::unique_ptr<Entity>> entities;
	public:
		void update()
		{
			for (auto& e : entities) e->update();
		}

		void draw()
		{
			for (auto& e : entities) e->render();
		}

		void refresh()
		{
			entities.erase(std::remove_if(std::begin(entities), std::end(entities),
				[](const std::unique_ptr<Entity>& mEntity)
				{
					return !mEntity->isActive();
				}),
				std::end(entities));
		}

		Entity& addEntity()
		{
			Entity* e = new Entity();
			std::unique_ptr<Entity> uPtr{ e };

			entities.emplace_back(std::move(uPtr));

			return *e;
		}
	};
}