#include "InputSystem.h"

namespace Game
{
	void InputSystem::Update()
	{
		lastFrameKeys.SetMask(thisFrameKeys); // 1

		thisFrameKeys.SetBit((int)Key::Left,
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ||
			(sf::Keyboard::isKeyPressed(sf::Keyboard::A))); // 2

		thisFrameKeys.SetBit((int)Key::Right,
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ||
			(sf::Keyboard::isKeyPressed(sf::Keyboard::D)));

		thisFrameKeys.SetBit((int)Key::Up,
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ||
			(sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

		thisFrameKeys.SetBit((int)Key::Down,
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) ||
			(sf::Keyboard::isKeyPressed(sf::Keyboard::S)));

		thisFrameKeys.SetBit((int)Key::Esc),
			sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
	}

	// Return true if the specified key is currently being pressed.
	bool InputSystem::IsKeyPressed(Key keycode)
	{
		return thisFrameKeys.GetBit((int)keycode);
	}

	// Returns true if the key was just pressed 
	// (i.e. registered as pressed this frame but not the previous).
	bool InputSystem::IsKeyDown(Key keycode)
	{
		bool lastFrame = lastFrameKeys.GetBit((int)keycode);
		bool thisFrame = thisFrameKeys.GetBit((int)keycode);

		return thisFrame && !lastFrame;
	}

	// Returns true if the key was just released (i.e. registered as 
	// pressed last frame but not the current frame).
	bool InputSystem::IsKeyUp(Key keycode)
	{
		bool lastFrame = lastFrameKeys.GetBit((int)keycode);
		bool thisFrame = thisFrameKeys.GetBit((int)keycode);

		return !thisFrame && lastFrame;
	}
}
