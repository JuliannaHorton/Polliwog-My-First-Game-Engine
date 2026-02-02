#include "DrawDeregistrationCommand.h"
#include "DrawAgent.h"

void DrawDeregistrationCmd::execute()
{
	DrawAgent::Registration::SceneDeregistration(ptrDraw);
}