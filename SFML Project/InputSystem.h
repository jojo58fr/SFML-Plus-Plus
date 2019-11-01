#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H
#pragma once

#include <SFML/Graphics.hpp>
#include "Bitmask.h"

namespace Game
{
	class InputSystem
	{
	public:
		enum class Key
		{
			None = 0,
			Left = 1,
			Right = 2,
			Up = 3,
			Down = 4,
			Esc = 5
		};

		void Update();

		bool IsKeyPressed(Key keycode); // Returns true if the key is pressed.
		bool IsKeyDown(Key keycode); // Returns true if the key was just pressed.
		bool IsKeyUp(Key keycode); // Returns true if the key was just released.

	private:
		Bitmask thisFrameKeys;
		Bitmask lastFrameKeys;
	};
}

#endif /* INPUTSYSTEM_H */
