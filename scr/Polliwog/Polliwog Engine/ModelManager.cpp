#include "ModelManager.h"
#include <iostream>

ModelManager* ModelManager::ptrInstance = nullptr;
std::map<std::string, Model*> ModelManager::modelMap;

void ModelManager::privLoad(std::string name, int x, int y, int z)
{
	Model* newModel = new Model(x, y, z);

	findName(name);
	modelMap[name] = newModel;
}

void ModelManager::privLoad(std::string name, std::string shader)
{
	std::string truePath = defaultPath + shader;
	Model* newModel = new Model(truePath.c_str());

	findName(name);
	modelMap[name] = newModel;
}

void ModelManager::privLoad(std::string name, Model::PreMadeModels modelType)
{
	modelType = Model::PreMadeModels::UnitSphere;
	Model* newModel = new Model(modelType); //I'll use UnitSphere for rn as a placeholder

	findName(name);
	modelMap[name] = newModel;
}

Model* ModelManager::privGet(std::string name)
{
	auto it = modelMap.find(name);

	if (it == modelMap.end())
	{
		std::string message = "\n!!!!\nCannot find the name: " + name + "\n!!!!\n\n";
		OutputDebugString(message.c_str());

		assert(false && "Cannot find a selected name, check output for more details"); //Is it better to throw an error?
	}

	return it->second;
}

void ModelManager::Terminate()
{
	// Delete the pointer to the dynamically allocated object
	for (auto const& deleteMe : modelMap) {
		delete deleteMe.second;
	}
	modelMap.clear();

	//Deleting Instance for the singleton
	delete ptrInstance;
	ptrInstance = nullptr;
}


void ModelManager::findName(std::string name)
{
	if (modelMap.find(name) != modelMap.end())
	{
		std::string message = "\n!!!!\nThe name " + name + " has already been used. Please pick a new name \n!!!!\n\n";
		OutputDebugString(message.c_str());

		assert(false && "This name has already been used, check output for more details");
	}
}
