#include "Updatable.h"
#include "SceneAgent.h"

Updatable::Updatable()
{
	pRegistrationCmd = new UpdateRegistrationCmd(this);
	pDeregistrationCmd = new UpdateDeregistrationCmd(this);

}

Updatable::~Updatable()
{
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
}

void Updatable::SubmitUpdateRegistration()
{
	assert(RegStateCurr == RegistrationState::CURRENTLY_DEREGISTERED);
	SceneAgent::Xables::SubmitCommand(SceneManager::getCurrentScene(), pRegistrationCmd);

	RegStateCurr = RegistrationState::PENDING_REGISTRATION;
}

void Updatable::SubmitUpdateDeregistration()
{
	assert(RegStateCurr == RegistrationState::CURRENTLY_REGISTERED);
	SceneAgent::Xables::SubmitCommand(SceneManager::getCurrentScene(), pDeregistrationCmd);

	RegStateCurr = RegistrationState::PENDING_DEREGISTRATION;
}

void Updatable::SceneRegistration()
{
	assert(RegStateCurr == RegistrationState::PENDING_REGISTRATION);
	SceneAgent::Xables::Register(this, pMyDeleteRef, SceneManager::getCurrentScene());

	RegStateCurr = RegistrationState::CURRENTLY_REGISTERED;
}

void Updatable::SceneDeregistration()
{
	assert(RegStateCurr == RegistrationState::PENDING_DEREGISTRATION);
	SceneAgent::Xables::Deregister(pMyDeleteRef, SceneManager::getCurrentScene());

	RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;

}

void Updatable::setDelete(const UpdateManager::StorageListRef& ref)
{
	pMyDeleteRef = ref;
}
