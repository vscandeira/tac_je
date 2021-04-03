#include "Sound.h"
#include "Game.h"

Sound::Sound(GameObject& associated) {
	this->associated = associated;
	chunk = nullptr;
}

Sound::Sound(GameObject& associated, std::string file) {
	Sound(associated);
	Open(file);

}

Sound::~Sound() {
	if (chunk != nullptr) {
		Mix_HaltChannel(channel);
		Mix_FreeChunk(chunk);
	}
}

void Play(int times/* = 1*/){
	if (IsOpen()) {
		Stop();
	}
	channel = Mix_PlayChannel(-1, chunk, times-1);
}
void Stop(){
	Mix_HaltChannel(channel);
}
void Open(std::string file){
	if (IsOpen()) {
		Stop();
	}
	chunk = Mix_LoadWAV(file.c_str());
	if (chunk == nullptr) {
		printError(SDL_GetError(),"Sound Mix_LoadWAV");
		return;
	}
}

bool IsOpen(){
	bool flag = false;
	if (chunk != nullptr) {
		flag = true;
	}
	return flag;
}

void Update(float dt){
	return;
}
void Render(){
	return;
}
bool Is(std::string type){
	bool flag = false;
	if (type.compare("Sound")==0) {
		flag = true;
	}
	return flag;
}
