#ifndef ENTITY_H
#define ENTITY_H
#pragma once

#include <bitset>
#include <array>
#include <vector>

#include "ECS.h"

namespace ECS
{
	constexpr std::size_t maxComponents = 32;

	using ComponentBitSet = std::bitset<maxComponents>;
	using ComponentArray = std::array<Component*, maxComponents>;

	class Entity
	{
	private:
		bool active = true;
		std::vector<std::unique_ptr<Component>> components;

		ComponentArray componentArray = {};
		ComponentBitSet componentBitSet = {};

	public:
		Entity() = default;

		void update()
		{
			for (auto& c : components) c->update();
		}

		//Draw function
		void render()
		{
			for (auto& c : components) c->render();
		}

		bool isActive() const { return active; }

		void destroy() { active = false; }

		template<typename T> bool hasComponent() const
		{
			return componentBitSet[getComponentTypeID<T>];
		}

		template<typename T, typename... TArgs>
		T& addComponent(TArgs&... mArgs)
		{
			T* c(new T(std::forward<TArgs>(mArgs)...));
			c->entity = this;
			std::unique_ptr<Component> uPtr{ c };
			components.emplace_back(std::move(uPtr));

			componentArray[getComponentTypeID<T>()] = c;
			componentBitSet[getComponentTypeID<T>()] = true;

			c->init();
			return *c;
		}

		template<typename T> T& getComponent() const
		{
			auto ptr(componentArray[getComponentTypeID<T>()]);
			return *static_cast<T*>(ptr);
		}

		//Example : gameobject.getComponent<PositionComponent>().setXpos(25);
	};
}

#endif /* ENTITY_H */
