#include "UpdateManager.h"
#include "UpdateAgent.h"

void UpdateManager::Register(Updatable* up, StorageListRef& ref)
{
	ref = storageList.insert(storageList.end(), up);

	up->setDelete(ref);
}

void UpdateManager::Deregister(const StorageListRef& ref)
{
	storageList.erase(ref);
}
  
void UpdateManager::ProcessElements()
{  
	//Called in the SceneManager Update
	//Update all the items in the list

	for (auto& up : storageList)
	{
		UpdateAgent::GameLoop::Update(up);
	}
}


