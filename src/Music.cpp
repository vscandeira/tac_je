#include "Music.h"
#include "Game.h"

Music::Music() {
	music = nullptr;
}

Music::Music(std::string file){
	music = nullptr;
	Open(file);
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
	} else if (times == -1) {
		Mix_PlayMusic(music, -1);
	}
}
void Music::Stop(int msToStop/*=1500*/){
	Mix_FadeOutMusic(msToStop);
}
void Music::Open(std::string file){
	if(Mix_LoadMUS(file.c_str())!=0){
		printError(SDL_GetError(),'M');
		return;
	}
}
