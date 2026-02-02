#pragma once

#ifndef _AlarmDeregistrationCmd
#define _AlarmDeregistrationCmd

#include "SceneCommand.h"

class Alarmable;

class AlarmDeregistrationCmd : public SceneCommand
{
public:

	AlarmDeregistrationCmd() = default;
	AlarmDeregistrationCmd(const AlarmDeregistrationCmd&) = delete;
	AlarmDeregistrationCmd& operator=(const AlarmDeregistrationCmd&) = delete;
	~AlarmDeregistrationCmd() = default; //This might be bad

	AlarmDeregistrationCmd(Alarmable* Alert) : ptrAlert(Alert) {};

	virtual void execute();

private:

	Alarmable* ptrAlert;
};


#endif _AlarmDeregistrationCmd