#ifndef _Drawable
#define _Drawable

#include "DrawManager.h"
#include "SceneManager.h"
#include "DrawRegistrationCommand.h"
#include "DrawDeregistrationCommand.h"

enum class RegistrationDrawState
{
	CURRENTLY_DEREGISTERED,
	PENDING_REGISTRATION,
	CURRENTLY_REGISTERED,
	PENDING_DEREGISTRATION
};

class Drawable
{
public:
	Drawable();
	Drawable(const Drawable&) = delete;
	Drawable& operator=(const Drawable&) = delete;
	virtual ~Drawable();

	void SubmitDrawRegistration();
	void SubmitDrawDeregistration();

	void setDelete(const DrawManager::StorageListRef& ref);

	friend class DrawAgent;

private:
	DrawManager::StorageListRef pMyDeleteRef;
	RegistrationDrawState RegStateCurr = RegistrationDrawState::CURRENTLY_DEREGISTERED;

	DrawRegistrationCmd* pRegistrationCmd;
	DrawDeregistrationCmd* pDeregistrationCmd;

	virtual void Draw() = 0;
	void SceneRegistration();
	void SceneDeregistration();
};


#endif _Drawable