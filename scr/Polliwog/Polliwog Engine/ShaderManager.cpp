#include "ShaderManager.h"

ShaderManager* ShaderManager::ptrInstance = nullptr;
std::map<std::string, ShaderObject*> ShaderManager::shaderMap;

void ShaderManager::privLoad(std::string name, std::string shader)
{
	std::string truePath = defaultPath + shader;
	ShaderObject* newShader = new ShaderObject(truePath.c_str());

	testName(name);
	shaderMap[name] = newShader;
}

ShaderObject* ShaderManager::privGet(std::string name)
{
	auto it = shaderMap.find(name);

	if (it == shaderMap.end())
	{
		std::string message = "\n!!!!\nCannot find the name: " + name + "\n!!!!\n\n";
		OutputDebugString(message.c_str());

		assert(false && "Cannot find a selected name, check output for more details"); //Is it better to throw an error?
	}

	return it->second;
}

ShaderObject* ShaderManager::privGet(DefaultShaders shaderType)
{
	switch (shaderType) 
	{
	case DefaultShaders::FlatRender:
		return shaderMap.find("DefaultFlat")->second;
	case DefaultShaders::LightRender:
		return shaderMap.find("DefaultLight")->second;
	default:
		return shaderMap.find("DefaultFlat")->second;
	}
}

void ShaderManager::privLoadDefaultResources()
{
	ShaderObject* flatShader = new ShaderObject("Shaders/textureFlatRender");
	shaderMap["DefaultFlat"] = flatShader;

	ShaderObject* lightShader = new ShaderObject("Shaders/textureLightRender");
	shaderMap["DefaultLight"] = lightShader;
}

void ShaderManager::Terminate()
{
	// Delete the pointer to the dynamically allocated object
	for (auto const& deleteMe : shaderMap) {
		delete deleteMe.second;
	}
	shaderMap.clear();

	//Deleting Instance for the singleton
	delete ptrInstance;
	ptrInstance = nullptr;
}



void ShaderManager::testName(std::string name)
{
	if (shaderMap.find(name) != shaderMap.end())
	{
		std::string message = "\n!!!!\nThe name " + name + " has already been used. Please pick a new name \n!!!!\n\n";
		OutputDebugString(message.c_str());

		assert(false && "This name has already been used, check output for more details"); //Is it better to throw an error?
	}
}