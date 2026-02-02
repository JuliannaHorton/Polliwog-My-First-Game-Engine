#include "DrawRegistrationCommand.h"
#include "DrawAgent.h"

void DrawRegistrationCmd::execute()
{
	DrawAgent::Registration::SceneRegistration(ptrDraw);
}