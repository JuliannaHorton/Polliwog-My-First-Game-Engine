//#pragma once
//
//#ifndef _AssetManager
//#define _AssetManager
//
//#include "Asset.h"
//#include <map>
//
//class AssetManager
//{
//private:
//	static AssetManager* ptrInstance;
//
//	AssetManager() = default;
//	AssetManager(const AssetManager&) = delete;
//	AssetManager& operator=(const AssetManager&) = delete;
//	~AssetManager() = default;
//
//	static AssetManager& Instance()
//	{
//		if (ptrInstance == nullptr)
//			ptrInstance = new AssetManager(); //WHY IS THIS REFERENCING A DELETED FUNCTION
//		return *ptrInstance;
//	};
//
//	void privDelete();
//	void privDraw();
//	void privInitStartScene();
//
//	Asset* privGetAsset(std::string);
//	void privSetStartScene(Scene* scene);
//
//	static Scene* currentScene;
//
//public:
//	static Scene* getCurrentScene() { return Instance().privGetCurrentScene(); };
//	static void setStartScene(Scene* s) { Instance().privSetStartScene(s); };
//
//	static void Delete() { Instance().privDelete(); };
//	static void Draw() { Instance().privDraw(); };
//	static void InitStartScene() { Instance().privInitStartScene(); };
//	static void Update() { Instance().privUpdate(); };
//
//};
//
//
////Ideas for future implementation:
////	- A real Asset Manage all the different asset types
////	- A parent class like this for asset classes
////	- Default assets for larger commonly used entities, such as collision wireframes (like the BSphere)
////	- Is it a bad idea to make asset factories?
//
//#endif _AssetManager