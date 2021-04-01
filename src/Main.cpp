/*
 * Main.cpp
 *  28/03/2021
 *  Victor Santos Candeira
 *  Matrícula 17/0157636
 */
#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "Sprite.h"
#include "Music.h"
#include "State.h"
#include "Game.h"


int main (int argc, char** argv) {
	Game game = Game::GetInstance();
	game.Run();
	return 0;
}

