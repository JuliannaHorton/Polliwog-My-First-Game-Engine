#include "SceneDemo.h"

void SceneDemo::Intialize()
{
	SpaceShip = new Frigate();
	Plane = new WorldPlane();
}


void SceneDemo::SceneEnd()
{
	delete SpaceShip;
	delete Plane;
}