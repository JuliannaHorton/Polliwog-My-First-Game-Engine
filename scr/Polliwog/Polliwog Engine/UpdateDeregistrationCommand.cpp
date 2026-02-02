#include "UpdateDeregistrationCommand.h"
#include "UpdateAgent.h"

void UpdateDeregistrationCmd::execute()
{
	UpdateAgent::Registration::SceneDeregistration(ptrUp);
}