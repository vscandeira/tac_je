/*
 * Main.cpp
 *  28/03/2021
 *  Victor Santos Candeira
 *  Matrícula 17/0157636
 */
#include <iostream>

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include "Game.h"


int main (int argc, char** argv) {
	Game game = Game::GetInstance();
	game.Run();
	return 0;
}

