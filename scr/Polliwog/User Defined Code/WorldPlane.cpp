#include "WorldPlane.h"
#include "../Polliwog Engine/CameraManager.h"
#include "../Polliwog Engine/ModelManager.h"
#include "../Polliwog Engine/ShaderManager.h"
#include "../Polliwog Engine/TextureManager.h"

#include "../Polliwog Engine/SceneManager.h"

WorldPlane::WorldPlane()
{

	pGObj_Plane = new GraphicsObject_TextureFlat(ModelManager::Get("ModelPlane"), ShaderManager::Get(ShaderManager::DefaultShaders::FlatRender), TextureManager::Get(TextureManager::DefaultTextures::TextTexture));
	pGObj_Axis = new GraphicsObject_ColorNoTexture(ModelManager::Get("ModelAxis"), ShaderManager::Get("noTexture"));
	
	World = Matrix(IDENTITY);
	pGObj_Axis->SetWorld(World);
	World = Matrix(IDENTITY);
	pGObj_Plane->SetWorld(World);

	Drawable::SubmitDrawRegistration();
}

void WorldPlane::Draw()
{
	pGObj_Plane->Render(CameraManager::getCurrentCamera());
	pGObj_Axis->Render(CameraManager::getCurrentCamera());
}

void WorldPlane::Update()
{

}

void WorldPlane::Alarm()
{

}

WorldPlane::~WorldPlane()
{
	delete pGObj_Plane;
	delete pGObj_Axis;
}