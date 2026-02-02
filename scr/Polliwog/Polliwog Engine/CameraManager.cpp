#include "CameraManager.h"

CameraManager* CameraManager::ptrInstance = nullptr;
std::map<std::string, Camera*> CameraManager::cameraMap;

CameraManager::CameraManager()
{
	Camera* Default = new Camera(Camera::Type::PERSPECTIVE_3D);
	Default->setViewport(0, 0, 960, 540);
	Default->setPerspective(35.0f, float(960) / float(540), 1.0f, 5000.0f); 

	// Orient Camera
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
	Default->setOrientAndPosition(defaultCameraUp, lookAt3DCam, pos3DCam);
	Default->updateCamera(); //Look this up

	activeCamera = Default;
	cameraMap[defaultCamera] = Default;

}

void CameraManager::privCreateCamera(std::string Name, Camera::Type camType, Vect Pos, Vect lookingAt)
{
	Camera* newCam = new Camera(camType);
	newCam->setOrientAndPosition(defaultCameraUp, lookingAt, Pos);
	newCam->setViewport(0, 0, 960, 540);
	newCam->setPerspective(35.0f, float(960) / float(540), 1.0f, 5000.0f);

	if (cameraMap.find(Name) != cameraMap.end())
	{
		std::string message = "\n!!!!\nThe name " + Name + " has already been used. Please pick a new name \n!!!!\n\n";
		OutputDebugString(message.c_str());

		assert(false && "This name has already been used, check output for more details"); //Is it better to throw an error?
	}

	cameraMap[defaultCamera] = newCam;
	newCam->updateCamera(); //Look this up
}

void CameraManager::privSwitchCamera(std::string Name)
{
	auto it = cameraMap.find(Name);

	if (it == cameraMap.end())
	{
		std::string message = "\n!!!!\nCannot find the name: " + Name + "\n!!!!\n\n";
		OutputDebugString(message.c_str());

		assert(false && "Cannot find a selected name, check output for more details"); //Is it better to throw an error?
	}

	activeCamera = it->second;
}

Camera* CameraManager::privGetCurrentCamera() //for right now I just have one camera
{
	return activeCamera;
}

void CameraManager::Terminate()
{
	for (auto const& deleteMe : cameraMap) {
		delete deleteMe.second;
	}
	cameraMap.clear();

	//Deleting Instance for the singleton
	delete ptrInstance;
	ptrInstance = nullptr;
}