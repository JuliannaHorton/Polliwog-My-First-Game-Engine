#pragma once

#ifndef _Asset
#define _Asset

class Asset
{
public:
	Asset() = default;
	Asset(const Asset&) = delete;
	Asset& operator=(const Asset&) = delete;
	~Asset() = default;

	// Note: the Excecute method must NOT have _any_ paramters
	virtual void Load(std::string, std::string) = 0;
	virtual void Get(std::string) = 0;
	virtual void Delete() = 0;

protected:
	//std::map<std::string, ShaderObject*> shaderMap;

	const std::string modelPath = "/Models";
	const std::string shaderPath = "/Shaders";
	const std::string texturePath = "/Textures";
};

#endif _Asset