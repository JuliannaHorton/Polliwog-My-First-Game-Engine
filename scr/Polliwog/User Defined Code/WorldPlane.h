#pragma once

#ifndef _WorldPlane
#define _WorldPlane

#include "../Polliwog Engine/GameObject.h"

class WorldPlane : public GameObject
{
public:
	WorldPlane();
	WorldPlane(const WorldPlane&) = delete;
	WorldPlane& operator=(const WorldPlane&) = delete;
	~WorldPlane();

	virtual void Draw();
	virtual void Update();
	virtual void Alarm();

private:

	GraphicsObject_TextureFlat* pGObj_Plane;
	GraphicsObject_ColorNoTexture* pGObj_Axis;

	Matrix World;

	const float ShipTransSpeed = 1;
	const float ShipRotAng = .05f;
};


#endif _WorldPlane