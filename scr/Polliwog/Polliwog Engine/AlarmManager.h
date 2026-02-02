#pragma once

#ifndef _AlarmManager
#define _AlarmManager

#include <map>

class Alarmable;

class AlarmManager
{
private:
	using TimeLineMap = std::multimap<float, Alarmable*>;
	TimeLineMap timeline;

	

public:
	AlarmManager() = default;
	AlarmManager(const AlarmManager&) = delete;
	AlarmManager& operator=(const AlarmManager&) = delete;
	~AlarmManager() = default;

	using StorageListRef = TimeLineMap::iterator;

	void Register(float t, Alarmable* drawing, StorageListRef& ref);
	void Deregister(const StorageListRef& ref);
	void ProcessAlarms();

};


#endif _AlarmManager