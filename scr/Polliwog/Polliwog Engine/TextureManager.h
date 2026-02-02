#pragma once

#ifndef _TextureManager
#define _TextureManager

#include "AzulCore.h"
#include "Asset.h"
#include <map>

class TextureManager
{
public:
	enum class DefaultTextures
	{
		TextTexture,
	};

	static void LoadDefaultResources() { Instance().privLoadDefaultResources(); };
	static void Load(std::string name, std::string shader) { Instance().privLoad(name, shader); };
	static Texture* Get(std::string name) { return Instance().privGet(name); };
	static Texture* Get(DefaultTextures textureType) { return Instance().privGet(textureType); };
	static void Terminate();

private:
	//Singleton
	static TextureManager* ptrInstance;

	TextureManager() = default;
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	~TextureManager() = default;

	static TextureManager& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new TextureManager();
		return *ptrInstance;
	};

	//Methods for asset control
	void privLoad(std::string, std::string); //key, name, renderfile
	Texture* privGet(std::string name);
	Texture* privGet(DefaultTextures);
	static void privLoadDefaultResources();


	//HashTable
	static std::map<std::string, Texture*> textureMap;
	const std::string defaultPath = "Textures/";

	void testName(std::string name); //Switch to main Asset Manager later
};

#endif _ShaderManager