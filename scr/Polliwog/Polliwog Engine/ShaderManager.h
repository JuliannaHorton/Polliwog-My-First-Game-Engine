#pragma once

#ifndef _ShaderManager
#define _ShaderManager

#include "AzulCore.h"
#include <map>

class ShaderManager
{
public:
	enum class DefaultShaders
	{
		FlatRender,
		LightRender
	};

	static void LoadDefaultResources() { Instance().privLoadDefaultResources(); };

	static void Load(std::string name, std::string shaderPath) { Instance().privLoad(name, shaderPath); };
	static ShaderObject* Get(std::string name) { return Instance().privGet(name); };
	static ShaderObject* Get(DefaultShaders shaderType) { return Instance().privGet(shaderType); };
	static void Terminate();

private:
	//Singleton
	static ShaderManager* ptrInstance;

	ShaderManager() = default;
	ShaderManager(const ShaderManager&) = delete;
	ShaderManager& operator=(const ShaderManager&) = delete;
	~ShaderManager() = default;

	static ShaderManager& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new ShaderManager(); //WHY IS THIS REFERENCING A DELETED FUNCTION
		return *ptrInstance;
	};

	//Methods for asset control
	void privLoad(std::string, std::string); //key, name, renderfile
	ShaderObject* privGet(std::string);
	ShaderObject* privGet(DefaultShaders);

	void privLoadDefaultResources();

	//Mapping
	static std::map<std::string, ShaderObject*> shaderMap; //Map
	const std::string defaultPath = "Shaders/"; //Default path

	void testName(std::string name); //Switch to main Asset Manager later
};

#endif _ShaderManager