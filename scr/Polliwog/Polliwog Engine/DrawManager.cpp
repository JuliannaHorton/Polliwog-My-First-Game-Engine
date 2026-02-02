#include "DrawManager.h"
#include "DrawAgent.h"

void DrawManager::Register(Drawable* draw, StorageListRef& ref)
{
	ref = storageList.insert(storageList.end(), draw);

	draw->setDelete(ref);
}

void DrawManager::Deregister(const StorageListRef& ref)
{
	storageList.erase(ref);
}

void DrawManager::ProcessElements()
{
	for (auto& drawing : storageList)
	{
		DrawAgent::GameLoop::Draw(drawing);
	}
}