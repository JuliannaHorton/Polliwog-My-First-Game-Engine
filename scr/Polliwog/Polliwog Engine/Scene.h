#pragma once

#ifndef _Scene
#define _Scene

#include "UpdateManager.h"
#include "DrawManager.h"
#include "AlarmManager.h"

#include "SceneCommand.h"
#include "SceneRegister.h"

class Scene
{
public:
	Scene() = default;
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
	virtual ~Scene() = default; //This might be bad

	//User defined
	virtual void Intialize() = 0;
	virtual void SceneEnd() = 0;

	friend class SceneAgent;

private:
	UpdateManager myUpdates;
	DrawManager myDrawings;
	AlarmManager myAlarms;

	SceneRegister myRegister;

	void Update();
	void Draw();

	void SubmitCommand(SceneCommand* cmd);

	void Register(Updatable*, UpdateManager::StorageListRef& deleteMe);
	void Deregister(const UpdateManager::StorageListRef& ref);
	void Register(Drawable*, DrawManager::StorageListRef& deleteMe);
	void Deregister(const DrawManager::StorageListRef& ref);
	void Register(float, Alarmable*, AlarmManager::StorageListRef& deleteMe);
	void Deregister(const AlarmManager::StorageListRef& ref);

};


#endif _Scene