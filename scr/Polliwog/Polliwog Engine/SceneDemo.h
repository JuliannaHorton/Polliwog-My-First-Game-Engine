#pragma once

#ifndef _SceneDemo
#define _SceneDemo

#include "Scene.h"
#include "../User Defined Code/Frigate.h"
#include "../User Defined Code/WorldPlane.h"

class SceneDemo : public Scene
{
public:
	SceneDemo() = default;
	SceneDemo(const SceneDemo&) = delete;
	SceneDemo& operator=(const SceneDemo&) = delete;
	~SceneDemo() = default;

	virtual void Intialize();
	virtual void SceneEnd();

private:

	Frigate* SpaceShip;
	WorldPlane* Plane;

};


#endif _SceneDemo