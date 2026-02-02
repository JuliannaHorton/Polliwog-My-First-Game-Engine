#include "AlarmRegistrationCommand.h"
#include "AlarmAgent.h"

void AlarmRegistrationCmd::execute()
{
	AlarmAgent::Registration::AlarmRegistration(time, ptrAlert);
}

void AlarmRegistrationCmd::setTime(float t)
{
	time = t;
}