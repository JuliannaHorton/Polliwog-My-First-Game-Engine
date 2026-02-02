#include "UpdateRegistrationCommand.h"
#include "UpdateAgent.h"

void UpdateRegistrationCmd::execute()
{
	UpdateAgent::Registration::SceneRegistration(ptrUp);
}