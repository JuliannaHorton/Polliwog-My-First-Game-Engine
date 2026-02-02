#ifndef _Alarmable
#define _Alarmable

#include "AlarmManager.h"
#include "AlarmRegistrationCommand.h"
#include "AlarmDeregistrationCommand.h"

enum class RegistrationAlarmState
{
	CURRENTLY_DEREGISTERED,
	PENDING_REGISTRATION,
	CURRENTLY_REGISTERED,
	PENDING_DEREGISTRATION
};

class Alarmable
{
public:
	Alarmable();
	Alarmable(const Alarmable&) = delete;
	Alarmable& operator=(const Alarmable&) = delete;
	virtual ~Alarmable();

	void SubmitAlarmRegistration(float t);
	void SubmitAlarmDeregistration();

	void setDelete(const AlarmManager::StorageListRef& ref);

	friend class AlarmAgent;

private:
	AlarmManager::StorageListRef pMyDeleteRef;
	RegistrationAlarmState RegStateCurr = RegistrationAlarmState::CURRENTLY_DEREGISTERED;

	AlarmRegistrationCmd* pRegistrationCmd;
	AlarmDeregistrationCmd* pDeregistrationCmd;

	void AlarmRegistration(float t);
	void AlarmDeregistration();

	virtual void Alarm() = 0;
	void TriggerAlarm();
};


#endif _Alarmable