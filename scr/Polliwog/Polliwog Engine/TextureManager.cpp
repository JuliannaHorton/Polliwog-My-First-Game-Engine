#include "TextureManager.h"

TextureManager* TextureManager::ptrInstance = nullptr;
std::map<std::string, Texture*> TextureManager::textureMap;

void TextureManager::privLoad(std::string name, std::string shader)
{
	std::string truePath = defaultPath + shader;
	Texture* newTexture = new Texture(truePath.c_str());

	testName(name);
	textureMap[name] = newTexture;


}

Texture* TextureManager::privGet(std::string name)
{
	auto it = textureMap.find(name);

	if (it == textureMap.end())
	{
		std::string message = "\n!!!!\nCannot find the name: " + name + "\n!!!!\n\n";
		OutputDebugString(message.c_str());

		assert(false && "Cannot find a selected name, check output for more details"); //Is it better to throw an error?
	}

	return it->second;
}

Texture* TextureManager::privGet(DefaultTextures textureType)
{
	switch (textureType)
	{
	case DefaultTextures::TextTexture:
		return textureMap.find("TextTexture")->second;
	default:
		return textureMap.find("TextTexture")->second;
	}
}

void TextureManager::privLoadDefaultResources()
{
	Texture* text = new Texture("Textures/grid.tga");
	textureMap["TextTexture"] = text;
}

void TextureManager::Terminate()
{
	// Delete the pointer to the dynamically allocated object
	for (auto const& deleteMe : textureMap) {
		delete deleteMe.second;
	}
	textureMap.clear();

	//Deleting Instance for the singleton
	delete ptrInstance;
	ptrInstance = nullptr;
}



void TextureManager::testName(std::string name)
{
	if (textureMap.find(name) != textureMap.end())
	{
		std::string message = "\n!!!!\nThe name " + name + " has already been used. Please pick a new name \n!!!!\n\n";
		OutputDebugString(message.c_str());

		assert(false && "This name has already been used, check output for more details"); //Is it better to throw an error?
	}
}