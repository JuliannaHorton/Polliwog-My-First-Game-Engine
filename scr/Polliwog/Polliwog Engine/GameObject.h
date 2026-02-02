#ifndef _GameObject
#define _GameObject

#include "Drawable.h"
#include "Updatable.h"
#include "Alarmable.h"
#include "AzulCore.h"

class GameObject : public Drawable, public Updatable, public Alarmable
{
public:
	GameObject() = default;
	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;
	~GameObject() = default;
};


#endif _GameObject