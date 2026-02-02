#include "Polliwog.h"
#include "CameraManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"
#include "ModelManager.h"
#include "SceneManager.h"

Polliwog* Polliwog::ptrInstance = nullptr;

void Polliwog::Initialize() //Engine Defined
{
	Polliwog::GameIntialize();
}

void Polliwog::LoadContent() 
{
	this->LoadResources();

	SceneManager::InitStartScene();
}

void Polliwog::Update()
{
	SceneManager::Update();
}

void Polliwog::Draw()
{
	SceneManager::Draw();
}

void Polliwog::UnLoadContent() //Engine Defined
{
	ShaderManager::Terminate();
	ModelManager::Terminate();
	TextureManager::Terminate();
	CameraManager::Terminate();

	SceneManager::Delete();
}

//get Methods
float Polliwog::privGetTime()
{
	return GetTimeInSeconds();
}

int Polliwog::privGetWidth()
{
	return getHeight();
}

int Polliwog::privGetHeight()
{
	return getWidth();
}

//Window Methods
void Polliwog::privSetWindowName(const char* n)
{
	this->setWindowName(n);
}

void Polliwog::privSetWindowSize(int w, int h)
{
	this->setWidthHeight(w, h);
}

void Polliwog::privSetWindowColor(float r, float g, float b, float o)
{
	this->SetClearColor(r, g, b, o); //Red, Green, Blue, Opacity
}

void Polliwog::privSetWindowColor(Vect Color)
{
	this->SetClearColor(Color.X(), Color.Y(), Color.Z(), Color.W());
}

void Polliwog::Terminate()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}


