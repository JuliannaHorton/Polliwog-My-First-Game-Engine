#pragma once

#ifndef _Frigate
#define _Frigate

#include "../Polliwog Engine/GameObject.h"

class Frigate : public GameObject
{
public:
	Frigate();
	Frigate(const Frigate&) = delete;
	Frigate& operator=(const Frigate&) = delete;
	~Frigate();

	void bSphere();

	virtual void Draw();
	virtual void Update();
	virtual void Alarm();

private:

	GraphicsObject_TextureFlat* pGObj_Plane;
	GraphicsObject_WireframeConstantColor* pGObj_SpaceshipBSphere;
	Matrix ShipScale;
	Matrix ShipRotTrans;
	Matrix World;

	const float ShipTransSpeed = 50;
	const float ShipRotAng = 2000;

	bool Donuts = true;
	bool BsphereToggle = false;
};


#endif _Frigate