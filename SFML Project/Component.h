#pragma once
#include "ECS.h";

namespace ECS
{
	class Component;
	class Entity;

	using ComponentID = std::size_t;

	inline ComponentID getComponentTypeID()
	{
		static ComponentID lastID = 0;
		return lastID++;
	}

	template <typename T> inline ComponentID getComponentTypeID() noexcept
	{
		static ComponentID typeID = getComponentTypeID();
		return typeID;
	}



	class Component
	{
	public:
		Entity* entity;

		Component() = default;
		virtual ~Component() {}

		virtual void init() {}
		virtual void update() {}
		virtual void render() {}

	private:

	};
}

