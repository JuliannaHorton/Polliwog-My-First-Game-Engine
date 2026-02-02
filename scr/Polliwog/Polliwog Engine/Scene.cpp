#include "Scene.h"

void Scene::Register(Updatable* Up, UpdateManager::StorageListRef& deleteMe)
{
	myUpdates.Register(Up, deleteMe);
}

void Scene::Deregister(const DrawManager::StorageListRef& ref)
{
	myDrawings.Deregister(ref);
}

void Scene::Register(Drawable* Draw, DrawManager::StorageListRef& deleteMe)
{
	myDrawings.Register(Draw, deleteMe);
}

void Scene::Deregister(const UpdateManager::StorageListRef& ref)
{
	myUpdates.Deregister(ref);
}

void Scene::Register(float t, Alarmable* Alert, AlarmManager::StorageListRef& deleteMe)
{
	myAlarms.Register(t, Alert, deleteMe);
}

void Scene::Deregister(const AlarmManager::StorageListRef& ref)
{
	myAlarms.Deregister(ref);
}

void Scene::Update()
{
	myRegister.executeCommands();

	myAlarms.ProcessAlarms();

	myUpdates.ProcessElements();
}

void Scene::Draw()
{
	myDrawings.ProcessElements();
}

void Scene::SubmitCommand(SceneCommand* cmd)
{
	myRegister.addCommand(cmd);
}