#include "Alarmable.h"
#include "SceneManager.h"
#include "SceneAgent.h"

Alarmable::Alarmable()
{
	pDeregistrationCmd = new AlarmDeregistrationCmd(this);
	pRegistrationCmd = new AlarmRegistrationCmd(this);
}

Alarmable::~Alarmable()
{
	delete pRegistrationCmd;
	delete pDeregistrationCmd;
}

void Alarmable::SubmitAlarmRegistration(float t)
{
	assert(RegStateCurr == RegistrationAlarmState::CURRENTLY_DEREGISTERED);

	pRegistrationCmd->setTime(t);
	SceneAgent::Xables::SubmitCommand(SceneManager::getCurrentScene(), pRegistrationCmd);

	RegStateCurr = RegistrationAlarmState::PENDING_REGISTRATION;
}

void Alarmable::SubmitAlarmDeregistration()
{
	assert(RegStateCurr == RegistrationAlarmState::CURRENTLY_REGISTERED);
	SceneAgent::Xables::SubmitCommand(SceneManager::getCurrentScene(), pDeregistrationCmd);

	RegStateCurr = RegistrationAlarmState::PENDING_DEREGISTRATION;
}

void Alarmable::AlarmRegistration(float t)
{
	assert(RegStateCurr == RegistrationAlarmState::PENDING_REGISTRATION);
	SceneAgent::Xables::Register(t, this, pMyDeleteRef, SceneManager::getCurrentScene());

	RegStateCurr = RegistrationAlarmState::CURRENTLY_REGISTERED;
}

void Alarmable::AlarmDeregistration()
{
	assert(RegStateCurr == RegistrationAlarmState::PENDING_DEREGISTRATION);
	SceneAgent::Xables::Deregister(SceneManager::getCurrentScene(), pMyDeleteRef);

	RegStateCurr = RegistrationAlarmState::CURRENTLY_DEREGISTERED;
}

void Alarmable::TriggerAlarm()
{
	RegStateCurr = RegistrationAlarmState::CURRENTLY_DEREGISTERED;

	this->Alarm();
}

void Alarmable::setDelete(const AlarmManager::StorageListRef& ref)
{
	pMyDeleteRef = ref;
}
