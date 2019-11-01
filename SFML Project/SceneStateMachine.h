#ifndef SCENESTATEMACHINE_H
#define SCENESTATEMACHINE_H
#pragma once

#include <memory>
#include <stack>
#include <unordered_map>

#include "SceneState.h"


using namespace std;

namespace Game
{
	class SceneStateMachine
	{
	public:
		SceneStateMachine();

		// ProcessInput, Update, LateUpdate, and Draw will simply be 
		// pass through methods. They will call the correspondingly 
		// named methods of the active scene.
		void ProcessInput();
		void Update(float deltaTime);
		void LateUpdate(float deltaTime);
		void Draw(Window* window);

		// Adds a scene to the state machine and returns the id of that scene.
		unsigned int Add(std::shared_ptr<SceneState> scene);

		// Transitions to scene with specified id.
		void SwitchTo(unsigned int id);

		// Removes scene from state machine.
		void Remove(unsigned int id);

	private:
		// Stores all of the scenes associated with this state machine.
		std::unordered_map<unsigned int, std::shared_ptr<SceneState>> scenes;

		// Stores a reference to the current scene. Used when drawing/updating.
		std::shared_ptr<SceneState> curScene;

		// Stores our current scene id. This is incremented whenever 
		// a scene is added.
		unsigned int insertedSceneID;
	};
}

#endif /* SCENESTATEMACHINE_H */
