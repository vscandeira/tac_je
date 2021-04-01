#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <string>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#include "Sprite.h"
#include "Music.h"
#include "State.h"

void printError(const char* erro, char debug);

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
