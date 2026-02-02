#pragma once

#ifndef _SceneManager
#define _SceneManager

#include "Scene.h"
#include <map>

class SceneManager
{
private:
	static SceneManager* ptrInstance;

	SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	~SceneManager() = default;

	static SceneManager& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new SceneManager(); //WHY IS THIS REFERENCING A DELETED FUNCTION
		return *ptrInstance;
	};

	void privDelete();
	void privDraw();
	void privInitStartScene();
	void privUpdate();

	Scene* privGetCurrentScene();
	void privSetStartScene(Scene* scene);

	static Scene* currentScene;

public:
	static Scene* getCurrentScene() { return Instance().privGetCurrentScene(); };
	static void setStartScene(Scene* s) { Instance().privSetStartScene(s); };

	static void Delete() { Instance().privDelete(); };
	static void Draw() { Instance().privDraw(); };
	static void InitStartScene() { Instance().privInitStartScene(); };
	static void Update() { Instance().privUpdate(); };
};


#endif _SceneManager