#include "Sound.h"
#include "Game.h"

Sound::Sound(GameObject& associated) : Component(associated) {
	this->associated = associated;
	chunk = nullptr;
	channel = 0;
}

Sound::Sound(GameObject& associated, std::string file) : Component(associated) {
	this->associated = associated;
	chunk = nullptr;
	channel = 0;
	Open(file);
}

Sound::~Sound() {
	if (chunk != nullptr) {
		Mix_HaltChannel(channel);
		Mix_FreeChunk(chunk);
		delete &channel;
	}
}

bool Sound::IsOpen(){
	bool flag = false;
	if (chunk != nullptr) {
		flag = true;
	}
	return flag;
}

void Sound::Stop(){
	Mix_HaltChannel(channel);
}

void Sound::Play(int times/* = 1*/){
	if (IsOpen()) {
		Stop();
	}
	channel = Mix_PlayChannel(-1, chunk, times-1);
}

void Sound::Open(std::string file){
	if (IsOpen()) {
		Stop();
	}
	chunk = Mix_LoadWAV(file.c_str());
	if (chunk == nullptr) {
		printError(SDL_GetError(),"Sound Mix_LoadWAV");
		return;
	}
}

void Sound::Update(float dt){
	return;
}
void Sound::Render(){
	return;
}
bool Sound::Is(std::string type){
	bool flag = false;
	if (type.compare("Sound")==0) {
		flag = true;
	}
	return flag;
}
