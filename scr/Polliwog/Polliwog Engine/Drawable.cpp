#include "Drawable.h"
#include "SceneAgent.h"

Drawable::Drawable()
{
	pRegistrationCmd = new DrawRegistrationCmd(this);
	pDeregistrationCmd = new DrawDeregistrationCmd(this);
}

Drawable::~Drawable()
{
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
}

void Drawable::SubmitDrawRegistration()
{
	assert(RegStateCurr == RegistrationDrawState::CURRENTLY_DEREGISTERED);
	SceneAgent::Xables::SubmitCommand(SceneManager::getCurrentScene(), pRegistrationCmd);

	RegStateCurr = RegistrationDrawState::PENDING_REGISTRATION;
}

void Drawable::SubmitDrawDeregistration()
{
	assert(RegStateCurr == RegistrationDrawState::CURRENTLY_REGISTERED);
	SceneAgent::Xables::SubmitCommand(SceneManager::getCurrentScene(), pDeregistrationCmd);

	RegStateCurr = RegistrationDrawState::PENDING_DEREGISTRATION;
}

void Drawable::SceneRegistration()
{
	assert(RegStateCurr == RegistrationDrawState::PENDING_REGISTRATION);
	SceneAgent::Xables::Register(this, pMyDeleteRef, SceneManager::getCurrentScene());

	RegStateCurr = RegistrationDrawState::CURRENTLY_REGISTERED;
}

void Drawable::SceneDeregistration()
{
	assert(RegStateCurr == RegistrationDrawState::PENDING_DEREGISTRATION);
	SceneAgent::Xables::Deregister(pMyDeleteRef, SceneManager::getCurrentScene());

	RegStateCurr = RegistrationDrawState::CURRENTLY_DEREGISTERED;
}

void Drawable::setDelete(const DrawManager::StorageListRef& ref)
{
	pMyDeleteRef = ref;
}