#include "Music.h"
#include "Game.h"

Music::Music() {
	music = nullptr;
}

Music::Music(std::string file){
	music = nullptr;
	Open(file);
	Play();
}

Music::~Music() {
	if (IsOpen()) {
		Stop();
		Mix_FreeMusic(music);
	}
}

bool Music::IsOpen() const{
	bool flag = false;
	if (music != nullptr) {
		flag = true;
	}
	return flag;
}

void Music::Play(int times/*=-1*/){
	if (IsOpen()) {
		Stop();
	}
	if (Mix_PlayMusic(music, times) < 0) {
		printError(SDL_GetError(),"Music Mix_PlayMusic");
	}
}
void Music::Stop(int msToStop/*=1500*/){
	Mix_FadeOutMusic(msToStop);
}
void Music::Open(std::string file){
	if (IsOpen()) {
		Stop();
	}
	music = Mix_LoadMUS(file.c_str());
	if(music==nullptr){
		printError(SDL_GetError(),"Music Mix_LoadMUS");
		return;
	}
}

