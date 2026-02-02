#pragma once

#ifndef _AlarmRegistrationCmd
#define _AlarmRegistrationCmd

#include "SceneCommand.h"

class Alarmable;

class AlarmRegistrationCmd : public SceneCommand
{
public:

	AlarmRegistrationCmd() = default;
	AlarmRegistrationCmd(const AlarmRegistrationCmd&) = delete;
	AlarmRegistrationCmd& operator=(const AlarmRegistrationCmd&) = delete;
	~AlarmRegistrationCmd() = default; //This might be bad

	AlarmRegistrationCmd(Alarmable* Alert) : ptrAlert(Alert), time(0) {};
	AlarmRegistrationCmd(float t, Alarmable* Alert) : ptrAlert(Alert), time(t) {};


	void setTime(float t);
	virtual void execute();

private:

	Alarmable* ptrAlert;
	float time;
};


#endif _AlarmRegistrationCmd