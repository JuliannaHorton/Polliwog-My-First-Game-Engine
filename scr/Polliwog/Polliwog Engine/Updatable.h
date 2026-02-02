#ifndef _Updatable
#define _Updatable

#include "UpdateManager.h"
#include "UpdateRegistrationCommand.h"
#include "UpdateDeregistrationCommand.h"
#include "SceneManager.h"

enum class RegistrationState
{
	CURRENTLY_DEREGISTERED,
	PENDING_REGISTRATION,
	CURRENTLY_REGISTERED,
	PENDING_DEREGISTRATION
};


class Updatable
{
public:
	Updatable();
	Updatable(const Updatable&) = delete;
	Updatable& operator=(const Updatable&) = delete;
	virtual ~Updatable();

	void SubmitUpdateRegistration();
	void SubmitUpdateDeregistration();

	void setDelete(const UpdateManager::StorageListRef& ref);

	friend class UpdateAgent;

private:
	UpdateManager::StorageListRef pMyDeleteRef;
	RegistrationState RegStateCurr = RegistrationState::CURRENTLY_DEREGISTERED;

	UpdateRegistrationCmd* pRegistrationCmd;
	UpdateDeregistrationCmd* pDeregistrationCmd;

	void SceneRegistration();
	void SceneDeregistration();

	virtual void Update() = 0;
};


#endif _Updatable