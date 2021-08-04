#include <iostream>

#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(GameObject& associated) : Component(associated) {
	texture = nullptr;
	width = 0;
	height = 0;
}
Sprite::Sprite(GameObject& associated, std::string file) : Component(associated){
	texture = nullptr;
	width = 0;
	height = 0;
	Open(file);
}
Sprite::~Sprite() {
	if(IsOpen()){
		SDL_DestroyTexture(texture);
	}
}

void Sprite::Open(std::string file) {
	SDL_Renderer* renderer = Game::GetInstance().GetRenderer();
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
	}
	texture = IMG_LoadTexture(renderer, file.c_str());
	if ( texture == nullptr) {
		printError(SDL_GetError(),"Sprite IMG_LoadTexture");
		return;
	}
	if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) < 0) {
		printError(SDL_GetError(),"Sprite SDL_QueryTexture");
		return;
	}
	SetClip(0,0,width,height);
}

void Sprite::SetClip(int x, int y, int w, int h){
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::Update(float dt){
	return;
}

void Sprite::Render(){
	SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

	SDL_Rect dstRect;
	if (this->width==1024 && this->height==600) {
		//imagem background
		dstRect.x = associated.box.x;
		dstRect.y = associated.box.y;
		dstRect.w = this->width;
		dstRect.h = this->height;
	} else {
		//imagem gos
		dstRect.x = associated.box.x - this->width/2;
		dstRect.y = associated.box.y - this->height/2;
		dstRect.w = this->width;
		dstRect.h = this->height;
	}

	if ( SDL_RenderCopy(renderer, texture, &clipRect, &dstRect) != 0) {
		printError(SDL_GetError(),"Sprite SDL_RenderCopy");
		return;
	}
	SDL_RenderPresent(renderer);
}

bool Sprite::Is(std::string type){
	bool flag = false;
	if (type.compare("Sprite")==0) {
		flag = true;
	}
	return flag;
}

int Sprite::GetWidth() const{
	return width;
}

int Sprite::GetHeight() const {
	return height;
}

bool Sprite::IsOpen() const{
	bool flag = false;
	if (texture != nullptr) {
		flag = true;
	}
	return flag;
}
