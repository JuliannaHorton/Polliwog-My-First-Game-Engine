#include "AzulCore.h"
#include <map>

#pragma once

#ifndef _CameraManager
#define _CameraManager

class CameraManager
{
private:
	static CameraManager* ptrInstance;

	CameraManager();
	CameraManager(const CameraManager&) = delete;				
	CameraManager& operator=(const CameraManager&) = delete;
	~CameraManager() = default;

	static CameraManager& Instance()
	{
		if (ptrInstance == nullptr)
			ptrInstance = new CameraManager();
		return *ptrInstance;
	};

	//Methods
	Camera* privGetCurrentCamera();
	void privCreateCamera(std::string name, Camera::Type camtype, Vect pos, Vect lookingat);
	//void RemoveCamera();
	void privSwitchCamera(std::string name); 
	
	//Attributes
	Camera* activeCamera;
	static std::map<std::string, Camera*> cameraMap; //I don't know if this will remain as a map

	const std::string defaultCamera = "DefaultCam"; //Default path
	const Vect defaultCameraUp = Vect(0.0f, 1.0f, 0.0f); //The 'Up' Camera Vector defines what direction is the top of the screen... I'm assuming the user will always want this facing upwards

public:					

	static Camera* getCurrentCamera() { return Instance().privGetCurrentCamera(); };
	static void createCamera(std::string name, Camera::Type camtype, Vect pos, Vect lookingat) { Instance().privCreateCamera(name, camtype, pos, lookingat); };
	static void switchCamera(std::string name) { Instance().privSwitchCamera(name); };
	
	static void Terminate();
};

#endif _CameraManager
