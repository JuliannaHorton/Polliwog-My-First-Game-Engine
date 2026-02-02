
#include "..\Polliwog Engine\Polliwog.h"
#include "..\Polliwog Engine\ShaderManager.h"
#include "..\Polliwog Engine\TextureManager.h"
#include "..\Polliwog Engine\ModelManager.h"
#include "..\Polliwog Engine\SceneManager.h"
#include "..\Polliwog Engine\SceneDemo.h"



void Polliwog::LoadResources()
{

	SceneManager::setStartScene(new SceneDemo());

	//---------------------------------------------------------------------------------------------------------
	// Load the Models
	//---------------------------------------------------------------------------------------------------------

	ModelManager::Load("ModelPlane", 400, 2, 2);
	ModelManager::Load("ModelAxis", "Axis.azul");

	ModelManager::Load("ModelFrigate", "space_frigate.azul");
	ModelManager::Load("ModelSphere", Model::PreMadeModels::UnitSphere);


	//---------------------------------------------------------------------------------------------------------
	// Load the Textures
	//---------------------------------------------------------------------------------------------------------

	// Direct loads
	TextureManager::Load("FrigateTex", "space_frigate.tga");
	TextureManager::Load("TextPlane", "grid.tga");
	TextureManager::LoadDefaultResources();

	//---------------------------------------------------------------------------------------------------------
	// Load the Shaders
	//---------------------------------------------------------------------------------------------------------
	// 
	ShaderManager::Load("color", "colorConstantRender");
	ShaderManager::Load("noTexture", "colorNoTextureRender");
	ShaderManager::LoadDefaultResources();
}