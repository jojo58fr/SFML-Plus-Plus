#include "SceneStateMachine.h"

namespace Game
{
	SceneStateMachine::SceneStateMachine() : scenes(0)
	{
		this->curScene = 0;
	}

	void SceneStateMachine::ProcessInput()
	{
		if (curScene)
		{
			curScene->ProcessInput();
		}
	}

	void SceneStateMachine::Update(float deltaTime)
	{
		if (curScene)
		{
			curScene->Update(deltaTime);
		}
	}

	void SceneStateMachine::LateUpdate(float deltaTime)
	{
		if (curScene)
		{
			curScene->LateUpdate(deltaTime);
		}
	}

	void SceneStateMachine::Draw(Window* window)
	{
		if (curScene)
		{
			curScene->Draw(window);
		}
	}

	unsigned int SceneStateMachine::Add(std::shared_ptr<SceneState> scene)
	{
		auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));

		insertedSceneID++;

		inserted.first->second->OnCreate();

		return insertedSceneID - 1;
	}

	void SceneStateMachine::Remove(unsigned int id)
	{
		auto it = scenes.find(id);
		if (it != scenes.end())
		{
			if (curScene == it->second)
			{
				// If the scene we are removing is the current scene, 
				// we also want to set that to a null pointer so the scene 
				// is no longer updated.
				curScene = nullptr;
			}

			// We make sure to call the OnDestroy method 
			// of the scene we are removing.
			it->second->OnDestroy();

			scenes.erase(it);
		}
	}

	void SceneStateMachine::SwitchTo(unsigned int id)
	{
		auto it = scenes.find(id);
		if (it != scenes.end())
		{
			if (curScene)
			{
				// If we have a current scene, we call its OnDeactivate method.
				curScene->OnDeactivate();
			}

			// Setting the current scene ensures that it is updated and drawn.
			curScene = it->second;

			curScene->OnActivate();
		}
	}

}
