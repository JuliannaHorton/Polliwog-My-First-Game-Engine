
#include "Polliwog.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{          
	// create Game
	//Game *pGame = new Game();    

	// start the game
	//pGame->run(); 
	Polliwog::funRun();

	Polliwog::Terminate();

	// "clean-up"... (not really for these demos)
	//delete pGame;

	return 0;                                       
}

