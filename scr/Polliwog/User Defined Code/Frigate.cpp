#include "Frigate.h"
#include "../Polliwog Engine/CameraManager.h"
#include "../Polliwog Engine/ModelManager.h"
#include "../Polliwog Engine/ShaderManager.h"
#include "../Polliwog Engine/TextureManager.h"

#include "../Polliwog Engine/SceneManager.h"

Frigate::Frigate()
{
	pGObj_Plane = new GraphicsObject_TextureFlat(ModelManager::Get("ModelFrigate"), ShaderManager::Get(ShaderManager::DefaultShaders::FlatRender), TextureManager::Get("FrigateTex"));

	Vect Blue(0.0f, 0.0f, 1.0f, 1.0f);
	pGObj_SpaceshipBSphere = new GraphicsObject_WireframeConstantColor(ModelManager::Get("ModelSphere"), ShaderManager::Get("color"), Blue);


	ShipScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	ShipRotTrans = Matrix(ROT_Y, 0) * Matrix(TRANS, 0, 20, 0);
	World = ShipScale * ShipRotTrans;
	pGObj_Plane->SetWorld(World);

	Updatable::SubmitUpdateRegistration();
	Drawable::SubmitDrawRegistration();
	Alarmable::SubmitAlarmRegistration(2);
}

Frigate::~Frigate()
{
	delete pGObj_Plane;
	delete pGObj_SpaceshipBSphere;
}

void Frigate::Draw()
{
	pGObj_Plane->Render(CameraManager::getCurrentCamera());

	if (BsphereToggle)
	{
		pGObj_SpaceshipBSphere->Render(CameraManager::getCurrentCamera());
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_W))
	{
		Drawable::SubmitDrawDeregistration();
	}
}

void Frigate::Alarm()
{
	Donuts = false;
	
	std::string message = "\n!!!!\nTrigger\n!!!!\n\n";
	OutputDebugString(message.c_str());
}

void Frigate::Update()
{
	World = ShipScale * ShipRotTrans;
	pGObj_Plane->SetWorld(World);

	if (Donuts != true)
	{
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_J))
		{
			ShipRotTrans = Matrix(ROT_Y, ShipRotAng) * ShipRotTrans;
		}
		else if (Keyboard::GetKeyState(AZUL_KEY::KEY_L))
		{
			ShipRotTrans = Matrix(ROT_Y, -ShipRotAng) * ShipRotTrans;
		}

		// Ship translation movement (not using time-based values for simplicity)
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_I))
		{
			ShipRotTrans = Matrix(TRANS, Vect(0, 0, ShipTransSpeed)) * ShipRotTrans;
		}
		else if (Keyboard::GetKeyState(AZUL_KEY::KEY_K))
		{
			ShipRotTrans = Matrix(TRANS, Vect(0, 0, -ShipTransSpeed)) * ShipRotTrans;
		}

		if (Keyboard::GetKeyState(AZUL_KEY::KEY_Q))
		{
			Updatable::SubmitUpdateDeregistration();
		}
	}
	else
	{
		ShipRotTrans = Matrix(ROT_Y, -ShipRotAng) * ShipRotTrans;
		ShipRotTrans = Matrix(TRANS, Vect(0, 0, ShipTransSpeed)) * ShipRotTrans;
	}

	bSphere();
}

void Frigate::bSphere()
{
	//*
	// Adjusting the spaceship's bounding sphere
	Vect vBSSize = pGObj_Plane->getModel()->getRadius() * Vect(1, 1, 1);
	Vect vBSPos = pGObj_Plane->getModel()->getCenter();

	//// Adjust the Bounding Sphere's position and scale to fit the Ship's center and scale
	Matrix worldBS = Matrix(SCALE, vBSSize) * Matrix(TRANS, vBSPos) * World;

	pGObj_SpaceshipBSphere->SetWorld(worldBS);

	//Toggle the bounding sphere's visibility
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_SPACE))
	{
		BsphereToggle = true;
		//DebugMsg::out("Bounding sphere: On\n");
	}
	else
	{
		BsphereToggle = false;
		//DebugMsg::out("Bounding sphere: Off\n");
	}
}
