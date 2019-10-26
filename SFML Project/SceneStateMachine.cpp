#include "SceneState.h"
#include "SceneStateMachine.h"

namespace Game
{

	/*void SceneStateMachine::AddState(StateRef newState, bool isReplacing)
	{
		this->isAdding = true;
		this->isReplacing = isReplacing;

		this->newState = move(newState);
	}

	void SceneStateMachine::RemoveState()
	{
		this->isRemoving = true;
	}

	void SceneStateMachine::ProcessStateChanges()
	{
		if (this->isRemoving && !this->states.empty())
		{
			this->states.pop();

			if (!this->states.empty())
			{
				this->states.top()->Resume();
			}

			this->isRemoving = false;
		}

		if (this->isAdding)
		{
			if (!this->states.empty())
			{
				if (this->isReplacing)
				{
					this->states.pop();
				}
				else
				{
					this->states.top()->Pause();
				}
			}

			this->states.push(move(this->newState));
			this->states.top()->Init();
			this->isAdding = false;
		}
	}

	StateRef& SceneStateMachine::GetActiveState()
	{
		return this->states.top();
	}*/

	SceneStateMachine::SceneStateMachine() : scenes(0), curScene(0) { }

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

	void SceneStateMachine::Draw(Window& window)
	{
		if (curScene)
		{
			curScene->Draw(window);
		}
	}

	unsigned int SceneStateMachine::Add(std::shared_ptr<SceneState> scene)
	{
		auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));

		inserted.first->second->OnCreate();

		return insertedSceneID++;
	}

	void SceneStateMachine::Remove(unsigned int id)
	{
		auto it = scenes.find(id);
		if (it != scenes.end())
		{
			if (curScene == it->second)
			{
				curScene = nullptr;
			}

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
				curScene->OnDeactivate();
			}

			curScene = it->second;

			curScene->OnActivate();
		}
	}

}
