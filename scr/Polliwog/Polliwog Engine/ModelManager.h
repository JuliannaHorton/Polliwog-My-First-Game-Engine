#pragma once

#ifndef _ModelManager
#define _ModelManager

#include "AzulCore.h"
#include <map>

class ModelManager
{
private:
	//Singleton
	static ModelManager* ptrInstance;

	ModelManager() = default;
	ModelManager(const ModelManager&) = delete;
	ModelManager& operator=(const ModelManager&) = delete;
	~ModelManager() = default;

	static ModelManager& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new ModelManager();
		return *ptrInstance;
	};

	//Methods for asset control
	void privLoad(std::string, int, int, int); //name, specifications
	void privLoad(std::string, std::string); //name, key
	void privLoad(std::string, Model::PreMadeModels model_type); //name, key
	Model* privGet(std::string name);

	//HashTable
	static std::map<std::string, Model*> modelMap;
	const std::string defaultPath = "Models/";

public:
	static void Load(std::string name, std::string shader) { Instance().privLoad(name, shader); };
	static void Load(std::string name, int planesize, int u, int v) { Instance().privLoad(name, planesize, u, v); };
	static void Load(std::string name, Model::PreMadeModels modelType) { Instance().privLoad(name,modelType); };
	static Model* Get(std::string name) { return Instance().privGet(name); };
	static void Terminate();

	void findName(std::string name); //Switch to main Asset Manager later

};

#endif _ShaderManager