#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

#include "Sprite.h"
#include "Music.h"
#include "State.h"

void printError(const char* erro, std::string debug);

class Game {
private:
	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;
	Game(std::string title="Victor Santos Candeira - 17/0157636", int width=1024,int height=600);
public:
	~Game();
	void Run();
	SDL_Renderer* GetRenderer() const;
	State& GetState() const;
	static Game& GetInstance();
};

#endif /* GAME_H_ */
