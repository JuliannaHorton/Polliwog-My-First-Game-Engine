#pragma once

#ifndef _DrawManager
#define _DrawManager

#include <list>

class Drawable; 

class DrawManager
{
private:
	using StorageList = std::list<Drawable*>;
	StorageList storageList;

public:
	DrawManager() = default;
	DrawManager(const DrawManager&) = delete;
	DrawManager& operator=(const DrawManager&) = delete;
	~DrawManager() = default;

	using StorageListRef = StorageList::iterator;

	void Register(Drawable* drawing, StorageListRef& ref);
	void Deregister(const StorageListRef& ref);
	void ProcessElements();

	
};


#endif _DrawManager