#include "Sprite.h"
#include "Game.h"
#include "GameObject.h"

Sprite::Sprite(GameObject& associated) : Component(GameObject& associated) {
	texture = nullptr;
	width = 0;
	height = 0;
}
Sprite::Sprite(std::string file){
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

void Sprite::Open(std::string file){
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
void Sprite::Render(){
	SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

	SDL_Rect dstRect;
	dstRect.x = 0;
	dstRect.y = 0;
	dstRect.w = clipRect.w;
	dstRect.h = clipRect.h;

	if ( SDL_RenderCopy(renderer, texture, &clipRect, &dstRect); != 0) {
		printError(SDL_GetError(),"Sprite SDL_RenderCopy");
		return;
	}
	SDL_RenderPresent(renderer);
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

bool Component::Is(std::string type){
	return false;
}

void Component::Update(float dt){
	return;
}
