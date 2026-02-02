#include "AlarmManager.h"
#include "AlarmAgent.h"
#include "Polliwog.h"

void AlarmManager::Register(float t, Alarmable* alert, StorageListRef& ref)
{
	ref = timeline.insert({ t, alert });

	alert->setDelete(ref);
}

void AlarmManager::Deregister(const StorageListRef& ref)
{
	timeline.erase(ref);
}

void AlarmManager::ProcessAlarms()
{
	auto alert = timeline.begin();
	float time = Polliwog::GetTime();

	while (!timeline.empty() && alert->first < time)
	{
		Alarmable* trigger = alert->second;
		AlarmAgent::GameLoop::TriggerAlarm(trigger);

		timeline.erase(alert);
	}
}