#include <iostream>

#include "State.h"
#include "Sprite.h"
#include "Music.h"

State::State() {
	bg = new Sprite("../assets/img/ocean.jpg");
	music = new Music("../assets/audio/stageState.ogg");
	//LoadAssets();
	quitRequested = false;
}

State::~State() {
	// TODO Auto-generated destructor stub
	delete bg;
	delete music;
	delete &quitRequested;
}

bool State::QuitRequested() const{
	return quitRequested;
}
void State::LoadAssets(){
	//bg->Open();
	//music->Open();
}
void State::Update(float dt){
	if (SDL_QuitRequested()) {
		quitRequested = true;
	}
}
void State::Render(){
	bg->Render(0,0);
}
