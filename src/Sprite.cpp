#include "Sprite.h"
#include "Game.h"

Sprite::Sprite() {
	texture = nullptr;
}
Sprite::Sprite(std::string file){
	texture = nullptr;
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
void Sprite::Render(int x, int y){
	SDL_Renderer* renderer = Game::GetInstance().GetRenderer();

	SDL_Rect dstRect;
	dstRect.x = x;
	dstRect.y = y;
	dstRect.w = clipRect.w;
	dstRect.h = clipRect.h;

	int a = SDL_RenderCopy(renderer, texture, &clipRect, &dstRect);
	if ( a != 0) {
		printError(SDL_GetError(),"Sprite SDL_RenderCopy");
		std::cout<<a<<std::endl;
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
