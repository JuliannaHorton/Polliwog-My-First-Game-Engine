#include "SceneManager.h"
#include "SceneAgent.h"

SceneManager* SceneManager::ptrInstance = nullptr;
Scene* SceneManager::currentScene;

void SceneManager::privSetStartScene(Scene* myScene)
{
	currentScene = myScene;
}

void SceneManager::privInitStartScene()
{
	assert(currentScene != nullptr && "Start scene is nullptr"); //Added pointer
	currentScene->Intialize();
}

void SceneManager::privUpdate()
{
	SceneAgent::GameLoop::Update(currentScene);
}

void SceneManager::privDraw()
{
	SceneAgent::GameLoop::Draw(currentScene);
}

Scene* SceneManager::privGetCurrentScene()
{
	return currentScene;
}

void SceneManager::privDelete()
{
	currentScene->SceneEnd();
	delete currentScene; //I had to make ~Scene() virual... which could be bad

	delete ptrInstance;
	ptrInstance = nullptr;
}
