#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(GameObject& associated) : Component(associated) {
	texture = nullptr;
	width = associated.box.w;
	height = associated.box.h;
}
Sprite::Sprite(GameObject& associated, std::string file) : Component(associated){
	texture = nullptr;
	width = associated.box.w;
	height = associated.box.h;
	Open(file);
}
Sprite::~Sprite() {
	if(IsOpen()){
		SDL_DestroyTexture(texture);
		delete &width;
		delete &height;
		delete &clipRect;

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
	dstRect.x = associated.box.x;
	dstRect.y = associated.box.y;
	dstRect.w = clipRect.w;
	dstRect.h = clipRect.h;

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
