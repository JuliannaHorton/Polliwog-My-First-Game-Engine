#include "AlarmDeregistrationCommand.h"
#include "AlarmAgent.h"

void AlarmDeregistrationCmd::execute()
{
	AlarmAgent::Registration::AlarmDeregistration(ptrAlert);
}