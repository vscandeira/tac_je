#include "Game.h"

Game* Game::instance=nullptr;

void printError(const char* erro, std::string debug) {
	std::cout << "Erro apresentado em " << debug << " - mensagem: " << erro <<std::endl;
}

Game::Game(std::string title/*="Victor Santos Candeira - 17/0157636"*/, int width/*=1024*/,int height/*=600*/) {
	instance = this;
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
		printError(SDL_GetError(),"Game SDL_Init");
		return;
	}
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
		printError(SDL_GetError(),"Game IMG_Init");
		return;
	}
	int flags=MIX_INIT_OGG|MIX_INIT_MOD;
	if ((Mix_Init(flags)&flags) != flags) {
		printError(Mix_GetError(), "Game Mix_Init");
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)  != 0) {
		printError(SDL_GetError(),"Game Mix_OpenAudio");
		return;
	}
	Mix_AllocateChannels(32); //default 8
	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	if (window == nullptr) {
		printError(SDL_GetError(),"Game SDL_CreateWindow");
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		printError(SDL_GetError(),"Game SDL_CreateRenderer");
		return;
	}
	state = new State();
}

Game& Game::GetInstance(){
	if (instance == nullptr) {
		new Game();
	}
	return *instance;
}

Game::~Game() {
	delete state;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
}

void Game::Run(){
	//1. Verifica, controla e carrega as telas de jogo;
	//2. Os dados de input são recebidos e processados;
	//3. Os objetos tem seus respectivos estados (posição, HP...) atualizados;
	//--------------------------------IMPLEMENTAR_SOMENTE_O_DEBAIXO-------------------------------
	//4. Os objetos são desenhados na tela
	float x = 0.0;
	while ( !( state->QuitRequested() ) ) {
		state->Update(x);
		state->Render();
		SDL_Delay(33);
	}
}
SDL_Renderer* Game::GetRenderer() const{
	return renderer;
}
State& Game::GetState() const{
	return *state;
}
